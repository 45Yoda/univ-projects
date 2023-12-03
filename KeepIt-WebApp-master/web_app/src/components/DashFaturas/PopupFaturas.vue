<template>
  <v-row justify="center">
    <v-btn color="primary" dark @click.stop="dialog = true">
      <v-icon>mdi-plus-box</v-icon>
    </v-btn>

    <v-dialog v-model="dialog" max-width="330">
      <v-card>
        <v-card-title>
          <h2>Adicione uma fatura</h2>
        </v-card-title>
        <v-card-text>
          <v-form class="px-3">
            <v-text-field v-model="receipt.company_id" label="ID Empresa"></v-text-field>
                 <v-text-field :rules="dataRules" v-model="receipt.date" label="Data"></v-text-field>
            <v-text-field v-model="receipt.total" label="Valor Total"></v-text-field>
            <v-combobox
            :items="['Restauração', 'Saúde', 'Despesas Gerais', 'Educação','Serviços', 'Transportes', 'Outros']"
            v-model="receipt.category"
            label="Categoria"
            chips>
    <template v-slot:selection="data">
        <v-chip :selected="data.selected"
                :color="getColor(data.item)">
            <strong>{{ data.item }}</strong>&nbsp;
        </v-chip>
    </template>
</v-combobox>
<template>
  <v-file-input prepend-icon="mdi-script" label="Adicionar Recibo" outlined dense></v-file-input>
</template>
            <!-- <v-select
                  chips
                   v-model = "receipt.category"
                  :items="['Restauração', 'Saúde', 'Despesas Gerais', 'Educação', 'Transportes', 'Outros']"
                  label="Categoria"
                  append-icon=mdi-plus-box
                  required
            ></v-select>-->
          </v-form>
          <v-btn @click="addReceipt">Adicionar Fatura</v-btn>
        </v-card-text>
      </v-card>
    </v-dialog>
  </v-row>
</template>

<script>
import axios from "axios";
import { mapGetters } from "vuex";

const lhost = require('@/config/routehost.js').host;

export default {
  data() {
    return {
     dataRules: [
            v => /.+-.+-.+/.test(v) || 'Date must be valid XX-XX-XXXX' 
      ],
      dialog: false,
      receipt: { company_id: "",date:"",cae:"", total: "", category: "" }
    };
  },
  computed: mapGetters(["getToken"]),
  methods: {
     getColor: function(category) {
      console.log(category);
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
    async addReceipt() {
      this.receipt.cae = this.receipt.category;
     await axios
        .post(lhost + "/receipts", this.receipt, {
          headers: { Authorization: "Bearer " + this.getToken }
        })
        .then(response => {
          console.log(this.receipt.category);
          console.log("response", response.data.status);
          switch (response.data.status) {
            case "OK":
              this.$router.push("/notfound");
              break;
            case "Receipt not added!":
              this.$router.push("/planos");
              break;
            case "User not found":
              this.$router.push("/home");
              break;
            default:
              console.log("It's Done!", response.data);
          }
        })
        .catch(err => {
          console.log(err + "aosfjidlfbhjh");
          this.$router.push("/notfound");
        });
          await  axios
        .get(lhost + "/users/update", {
          headers: { Authorization: "Bearer " + this.getToken }
        })
        .then(()=> {
        });
    }
  }
};
</script>