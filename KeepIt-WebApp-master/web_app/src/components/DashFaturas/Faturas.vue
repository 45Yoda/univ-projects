<template>
  <div>
    <v-toolbar color="#3cbda9" max-height="10px"></v-toolbar>

    <v-card color="#3d3a3a">
      <v-card-title>
        Faturas
        <v-spacer></v-spacer>
        <v-row>
          <v-col cols="12" lg="10">
            <v-text-field
              v-model="search"
              append-icon="mdi-magnify"
              label="Search"
              single-line
              hide-details
            ></v-text-field>
          </v-col>

          <v-col cols="12" lg="2">
            <Popup></Popup>
          </v-col>
        </v-row>
      </v-card-title>

      <v-data-table
        dark
        style="background-color:#3d3a3a"
        :headers="headers"
        :items="faturas"
        :search="search"
        :footer-props="{ 'items-per-page-options': [5,10, 30],
                           'items-per-page-text': 'Mostrar:'}"
      >
        <template v-slot:top>
          <v-divider class="mx-4" inset vertical></v-divider>
          <v-spacer></v-spacer>
          <v-dialog v-model="dialog" max-width="500px">
            <template v-slot:activator="{}"></template>
            <v-card>
              <v-card-title>
                <span class="headline">Editar Fatura</span>
              </v-card-title>

              <v-card-text>
                <v-container>
                  <v-row>
                    <v-col cols="12" sm="6" md="4">
                      <v-combobox
                        :items="['Restauração', 'Saúde', 'Despesas Gerais', 'Educação','Serviços', 'Transportes', 'Outros']"
                        v-model="receipt.category"
                        label="Categoria"
                        chips
                      >
                        <template v-slot:selection="data">
                          <v-chip :selected="data.selected" :color="getColor(data.item)">
                            <strong>{{ data.item }}</strong>&nbsp;
                          </v-chip>
                        </template>
                      </v-combobox>
                    </v-col>
                    <v-col cols="12" sm="6" md="4">
                      <v-text-field v-model="receipt.company_id" label="ID Empresa"></v-text-field>
                    </v-col>
                    <v-col cols="12" sm="6" md="4">
                      <v-text-field v-model="receipt.date" label="Data"></v-text-field>
                    </v-col>
                    <v-col cols="12" sm="6" md="4">
                      <v-switch v-model="receipt.is_warranty" label="Garantia"></v-switch>
                      <!-- <v-text-field v-model="receipt.is_warranty" label="Garantia"></v-text-field> -->
                    </v-col>
                    <v-col cols="12" sm="6" md="4">
                      <v-text-field v-model="receipt.total" label="Total"></v-text-field>
                    </v-col>
                  </v-row>
                </v-container>
              </v-card-text>

              <v-card-actions>
                <v-spacer></v-spacer>
                <v-btn color="blue darken-1" text @click="close">Cancelar</v-btn>
                <v-btn color="blue darken-1" text @click="save">Guardar</v-btn>
              </v-card-actions>
            </v-card>
          </v-dialog>
          <v-dialog v-model="share" max-width="500px">
            <template v-slot:activator="{ }"></template>
            <v-card>
              <v-card-title>
                <span class="headline">Partilhar Fatura</span>
              </v-card-title>

              <v-card-text>
                <v-container>
                  <v-row>
                    <v-col cols="12">
                      <v-combobox
                        :rules="[v => !!v[0] || 'Campo obrigatório!']"
                        multiple
                        solo
                        clearable
                        v-model="emails"
                        chips
                        deletable-chips
                        label="Email para partilhar Fatura"
                      ></v-combobox>
                      <v-row>
                        <v-col cols="12" lg="8">
                          <v-select
                            small
                            flat
                            prefix="Dividir recibo em partes iguais?"
                            :items="['Sim', 'Não']"
                            label
                            v-model="escolha"
                            solo
                          ></v-select>
                        </v-col>
                        <v-col v-if="escolha=='Não'" cols="12" lg="4">
                          <v-text-field
                            v-for="mail in convertedArray"
                            v-bind:key="mail.email"
                            v-bind:label="$t(mail.email)"
                            v-model="mail.total"
                            required
                          ></v-text-field>
                          <!-- <v-text-field v-if="escolha" v-bind:label="$t('My Label')" required></v-text-field> -->
                        </v-col>
                      </v-row>
                    </v-col>
                  </v-row>
                  <v-row>
                    <v-col cols="12">
                      <v-switch v-model="want_share" label="Deseja alterar o dono da Fatura? "></v-switch>
                      <!-- <v-text-field v-model="receipt.is_warranty" label="Garantia"></v-text-field> -->
                    </v-col>
                  </v-row>
                </v-container>
              </v-card-text>
              <template v-if="success">
                <v-alert dense type="success">O utilizador com esse email Existe</v-alert>
              </template>
              <v-card-actions>
                <v-spacer></v-spacer>
                <v-btn color="blue darken-1" text @click="close">Cancelar</v-btn>
                <v-btn color="blue darken-1" text @click="shareR">Partilhar</v-btn>
              </v-card-actions>
            </v-card>
          </v-dialog>
        </template>
        <template v-slot:item.category="{ item }">
          <v-chip :color="getColor(item.category)" dark>{{ item.category }}</v-chip>
        </template>
        <template v-slot:item.iconb="{ item }">
          <v-icon @click="showpdf(item)">mdi-arrow-right</v-icon>
        </template>
        <template v-slot:item.icon="{ item }">
          <v-icon @click="altWarranty(item)" v-if="item.is_warranty ">mdi-star</v-icon>
          <v-icon @click="altWarranty(item)" v-else>mdi-star-outline</v-icon>
        </template>
        <template v-slot:item.action="{ item }">
          <v-icon small class="mr-2" @click="editItem(item)">mdi-border-color</v-icon>
          <v-icon small @click="deleteItem(item)">mdi-delete</v-icon>
          <v-icon small class="mr-2" @click="shareReceipt(item)">mdi-share-variant</v-icon>
        </template>
        <template v-slot:no-data>
          <v-alert :value="true" color="orange" icon="mdi-alert">Não Existem Faturas</v-alert>
        </template>
        <template v-slot:body.append>
          <tr>
            <td></td>
            <td>
              <v-text-field v-model="total" type="string" label="Less than"></v-text-field>
            </td>
            <td colspan="4"></td>
          </tr>
        </template>
      </v-data-table>
    </v-card>
  </div>
</template>

<script>
import { mapGetters, mapMutations } from "vuex";
import axios from "axios";
import Popup from "../DashFaturas/PopupFaturas";

const lhost = require("@/config/routehost.js").host;

export default {
  data() {
    return {
      convertedArray: [],
      escolha: "",
      timer: "",
      emails: [],
      mail: {
        user: "",
        total: null
      },
      valDiv: [],
      success: false,
      want_share: false,
      share: false,
      dialog: false,
      idEnv: "",
      idOwner: "",
      emailEnv: "",
      email: "",
      index: 0,
      link: "",
      receipt: "",
      editedIndex: -1,
      search: "",
      total: "",
      faturas: [],
      editedItem: {
        name: "",
        calories: 0,
        fat: 0,
        carbs: 0,
        protein: 0
      },
      defaultItem: {
        name: "",
        calories: 0,
        fat: 0,
        carbs: 0,
        protein: 0
      },
      filter: [
        { title: "filtro1" },
        { title: "Filtro2" },
        { title: "Filtro3" },
        { title: "Filtro4" }
      ],
      headers: [
        {
          text: "Categorias",
          align: "left",
          value: "category"
        },
        {
          text: "Valor",
          value: "total",
          filter: value => {
            if (!this.total) return true;
            return value < parseInt(this.total);
          }
        },
        { text: "Data", value: "date" },
        { text: "Garantia", value: "icon" },
        //        { text: "Garantia", value: "is_warranty" },
        { text: "", value: "iconb", sortable: false },
        { text: "", value: "action", sortable: false }
      ]
    };
  },
  components: { Popup },
  computed: {
    ...mapGetters(["getToken"]),
    convertArray() {
      return this.emails.map(e => {
        let newUser = {
          email: e,
          total: 0
        };
        return newUser;
      });
    }
  },
  watch: {
    emails() {
      this.convertedArray = this.emails.map(e => {
        let newUser = {
          email: e,
          total: 0
        };
        return newUser;
      });

      console.log("velho ", this.convertedArray);
    }
  },

  created() {
    // this.timer = setInterval(this.refresh, 120000);
    this.timer = setInterval(this.refresh, 3000);
  },
  cancelAutoUpdate() {
    clearInterval(this.timer);
  },
  beforeDestroy() {
    clearInterval(this.timer);
  },

  methods: {
    ...mapMutations(["removeToken"]),
    $t(value) {
      return value;
    },
    toggleIcon() {
      this.success = !this.success;
    },

    altWarranty: function(item) {
      this.id = this.faturas[this.faturas.indexOf(item)]["_id"];

      if (item.is_warranty == false) {
        axios({
          method: "PATCH",
          url: lhost + "/receipts/" + this.id,
          data: {
            is_warranty: true
          },
          headers: { Authorization: "Bearer " + this.getToken }
        }).then(() => {
          item.is_warranty = true;
        });
      } else if (item.is_warranty == true) {
        axios({
          method: "PATCH",
          url: lhost + "/receipts/" + this.id,
          data: {
            is_warranty: false
          },
          headers: { Authorization: "Bearer " + this.getToken }
        }).then(() => {
          item.is_warranty = false;
        });
      }
    },
    getColorGarantia: function(garantia) {
      switch (garantia) {
        case true:
          return "rgb(0,255,0)";
        case false:
          return "rgb(255,0,0)";
      }
    },
    getColor: function(category) {
      switch (category) {
        case "Restauração":
          return "rgb(0,255,0)";
        case "Saúde":
          return "rgb(255,0,0)";
        case "Despesas Gerais":
          return "rgb(0,0,255)";
        case "Educação":
          return "rgb(255, 152, 0)";
        case "Transportes":
          return "rgb(255, 255, 0)";
        case "Serviços":
          return "rgb(233,30,99)";
        case "Outros":
          return "rgb(156, 39, 176)";
      }
    },
    editItem(item) {
      this.editedIndex = this.faturas.indexOf(item);
      this.editedItem = Object.assign({}, item);
      this.dialog = true;
      this.id = this.faturas[this.faturas.indexOf(item)]["_id"];
      //const index = this.faturas.indexOf(item)

      axios
        .get(lhost + "/receipts/" + this.id, {
          headers: { Authorization: "Bearer " + this.getToken }
        })
        .then(res => {
          this.receipt = res.data;
        });
    },
    shareReceipt(item) {
      this.id = this.faturas[this.faturas.indexOf(item)]["_id"];
      this.share = true;
      axios
        .get(lhost + "/receipts/" + this.id, {
          headers: { Authorization: "Bearer " + this.getToken }
        })
        .then(res => {
          this.receipt = res.data;
        });
    },

    deleteItem(item) {
      this.id = this.faturas[this.faturas.indexOf(item)]["_id"];
      var result = confirm("Quer eliminar os dados das estatísticas?");

      if (result == true) {
        axios
          .delete(lhost + "/receipts/" + this.id, {
            params: {
              ask: true
            },
            headers: { Authorization: "Bearer " + this.getToken }
          })
          .then(() => {});
      } else {
        axios
          .delete(lhost + "/receipts/" + this.id, {
            headers: { Authorization: "Bearer " + this.getToken }
          })
          .then(() => {});
      }
      //  confirm('Are you sure you want to delete this item?') && this.faturas.splice(index, 1)
    },
    close() {
      this.dialog = false;
      setTimeout(() => {
        this.editedItem = Object.assign({}, this.defaultItem);
        this.editedIndex = -1;
      }, 300);
    },

    async shareR() {
      await axios
        .get(lhost + "/users/email/" + this.emailEnv, {
          headers: { Authorization: "Bearer " + this.getToken }
        })
        .then(res => {
          this.idEnv = res.data[0]._id;
        });
      await axios
        .get(lhost + "/users", {
          headers: { Authorization: "Bearer " + this.getToken }
        })
        .then(res => {
          this.idOwner = res.data._id;
        });
      console.log(this.idEnv + "ola" + this.receipt.total);

      if (this.want_share == false) {
        //false
        await axios({
          method: "PATCH",
          url: lhost + "/receipts/shared/" + this.id,
          params: {
            ask: false
          },
          data: [
            {
              total: 5,
              user_id: this.idEnv
            }
          ],
          headers: { Authorization: "Bearer " + this.getToken }
        }).then(res => {
          this.success = true;
          console.log(res.data);
        });
      } else {
        await axios({
          method: "PATCH",
          url: lhost + "/receipts/shared/" + this.id,
          params: {
            ask: true
          },
          data: {
            owner: {
              total: 10,
              user_id: this.idEnv
            },
            shared: []
          },
          headers: { Authorization: "Bearer " + this.getToken }
        }).then(res => {
          this.success = true;
          console.log(res.data);
        });
      }
      await axios
        .get(lhost + "/users/update", {
          headers: { Authorization: "Bearer " + this.getToken }
        })
        .then(() => {});
    },

    async save() {
      await axios({
        method: "PATCH",
        url: lhost + "/receipts/" + this.id,
        data: {
          category: this.receipt.category,
          company_id: this.receipt.company_id,
          date: this.receipt.date,
          is_warranty: this.receipt.is_warranty,
          total: this.receipt.total
        },
        headers: { Authorization: "Bearer " + this.getToken }
      }).then(() => {});

      await axios
        .get(lhost + "/users/update", {
          headers: { Authorization: "Bearer " + this.getToken }
        })
        .then(() => {});
    },
    showpdf(item) {
      this.id = this.faturas[this.faturas.indexOf(item)]["_id"];
      this.$emit("showfatura", "true");
      this.link = "http://142.93.140.126:2014/receipts/" + this.id + "/pdf";

      this.$emit("sendlink", this.link);
    },

    refresh() {
      try {
        axios
          .get(lhost + "/receipts/", {
            headers: { Authorization: "Bearer " + this.getToken }
          })
          .then(res => {
            if (res.data.status == "ERROR INVALID TOKEN") {
              localStorage.removeItem("access_token");
              this.removeToken();
              this.$router.push("/login");
            } else {
              this.faturas = res.data;
            }
          })
          .catch(err => {
            console.log("Catch " + err);
          });
      } catch (e) {
        console.log("ERROR: " + e);
        return e;
      }
    }
  },
  mounted: function() {
    try {
      axios
        .get(lhost + "/receipts/", {
          headers: { Authorization: "Bearer " + this.getToken }
        })
        .then(res => {
          if (res.data.status == "ERROR INVALID TOKEN") {
            localStorage.removeItem("access_token");
            this.removeToken();
            this.$router.push("/login");
          } else {
            this.faturas = res.data;
          }
        })
        .catch(err => {
          console.log("Catch " + err);
        });
    } catch (e) {
      console.log("ERROR: " + e);
      return e;
    }
  }
};
</script>

<style scoped>
</style>