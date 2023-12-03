<template>
  <v-card max-width="70%">
    <v-container fill-height fluid grid-list-xl>
      <v-layout justify-center wrap>
        <v-flex xs12 md8>
          <v-flex>
            <material-card name class="v-card-profile">
              <v-avatar slot="offset" class="mx-auto d-block" size="150">
                <!-- <div>
              <input type="file" @change="onFileSelected">
                </div>-->
                <img
                  src="https://demos.creative-tim.com/vue-material-dashboard/img/marc.aba54d65.jpg"
                />
              </v-avatar>
              <v-card-text class="text-xs-center">
                <v-btn
                  @click="onFileSelected"
                  color="success"
                  rounded
                  class="font-weight-light"
                >Alterar foto de Perfil</v-btn>
              </v-card-text>
            </material-card>
          </v-flex>
          <material-card color="green" title="Edit Profile" text="Complete your profile">
            <v-form>
              <v-container py-0>
                <v-layout wrap>
                  <v-flex xs12 md4>
                    <v-text-field label="Nome" v-model="nome" />
                  </v-flex>
                  <v-flex xs12 md4>
                    <v-text-field class="purple-input" label="Email" v-model="email" />
                  </v-flex>
                  <v-flex xs12 md4>
                    <v-text-field label="Keep_Email" v-model="emailkeep" class="purple-input" />
                  </v-flex>
                  <v-flex xs12 md6>
                    <v-text-field
                      label="Data de Nascimento"
                      class="purple-input"
                      v-model="data_nasc"
                    />
                  </v-flex>
                  <v-flex xs12 md4>
                    <v-text-field label="Cidade" class="purple-input" v-model="cidade" />
                  </v-flex>
                  <v-flex xs12 md4>
                    <v-text-field label="País" class="purple-input" v-model="pais" />
                  </v-flex>
                  <v-flex xs12 md4>
                    <v-text-field
                      class="purple-input"
                      label="Codigo Postal"
                      v-model="codigo_postal"
                      type="number"
                    />
                  </v-flex>
                  <v-flex xs12></v-flex>
                  <v-flex xs12 text-xs-right>
                    <v-btn
                      class="mx-0 font-weight-light"
                      color="success"
                      @click="editProfile"
                    >Update Profile</v-btn>
                  </v-flex>
                </v-layout>
              </v-container>
            </v-form>
          </material-card>
        </v-flex>
      </v-layout>
    </v-container>
  </v-card>
</template>

<script>
import { mapGetters } from "vuex";
import axios from "axios";

const lhost = require('@/config/routehost.js').host;

export default {
  data() {
    return {
      selectedFile: null,
      nome: "",
      email: "",
      emailkeep: "",
      data_nasc: "",
      morada: "",
      cidade: "",
      pais: "",
      codigo_postal: ""
    };
  },
  
  computed:{
     computedDateFormatted() {
       console.log(this.data_nasc)
      return this.formatDate(this.data_nasc);
    },
    ...mapGetters(["getToken"]),
  },
  watch : {
     date() {
      this.dateFormatted = this.formatDate(this.data_nasc);
    },
  },
  methods: {
    formatDate(date) {
      if (!date) return null;

      const [ year,month, day] = date.split("-");
      const test = `${day}`.split("T")[0]
      return `${test}-${month}-${year}`;
    },
    onFileSelected() {
      console.log(this.nome);
    },
    editProfile() {
      console.log(
        this.nome +
          this.email +
          this.emailkeep +
          this.data_nasc +
          this.pais +
          this.cidade
      );
      axios({
        method: "PATCH",
        url: lhost + "/users",
        data: {
          name: this.nome,
          email: this.email,
          keep_email: this.emailkeep,
          birth: this.data_nasc,
          country: this.pais,
          district: this.cidade
        },
        headers: { Authorization: "Bearer " + this.getToken }
      }).then(res => {
        console.log(res.data);
      });
    }
  },
  mounted: function() {
    axios
      .get(lhost + "/users", {
        headers: { Authorization: "Bearer " + this.getToken }
      })
      .then(res => {
        console.log(res.data);
        this.email = res.data.email;
        console.log(res.data.email);
        this.nome = res.data.name;
        this.emailkeep = res.data.keep_email;
        this.pais = res.data.country;
        this.cidade = res.data.district;
        this.data_nasc = this.formatDate(res.data.birth);
        console.log(this.data_nasc)
      });
  }
};
</script>