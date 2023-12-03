<template>
  <v-card style="background-color:#1b524d" lass="mx-auto">
    <v-toolbar color="#3cbda9" max-height="10px"></v-toolbar>
    <v-tabs v-model="model" centered slider-color="#3cbda9" background-color="transparent">
      <v-tab
        v-for="(f,index) in months"
        @click="next"
        class="ListItem"
        :key="f.nome"
        :href="`#tab-${index+1}`"
      >{{f.nome}}</v-tab>
    </v-tabs>
    <v-tabs-items  v-model="model">
      <v-tab-item  v-for="i in 3" :key="i" :value="`tab-${i}`">
        <v-list dense color="#314e4a" two-line >
          <v-list-item  dense v-for="item in stats" :key="item.category">
            <template v-slot:default="{}">
              <v-list-item-content > 
                <v-row>
                  <v-col cols="12" lg="2" md="3" sm="3" xs="2">
                    <v-icon dark v-if="item.category == 'Restauração'" >mdi-silverware-fork-knife</v-icon>
                    <v-icon dark v-if="item.category == 'Saúde'" >mdi-bottle-tonic-plus</v-icon>
                    <v-icon dark v-if="item.category == 'Serviços'" >mdi-cart </v-icon>
                    <v-icon dark v-if="item.category == 'Despesas Gerais'">mdi-home-account</v-icon>
                    <v-icon dark v-if="item.category == 'Transportes'" >mdi-train-car</v-icon>
                    <v-icon dark v-if="item.category == 'Educação'" >mdi-school</v-icon>
                    <v-icon dark v-if="item.category == 'Outros'" >mdi-dots-horizontal-circle-outline</v-icon>
                  </v-col>
                  <v-col cols="12" lg="5" md="3" sm="3" xs="3">
                    <v-list-item-title class="ListItem" v-text="item.category"></v-list-item-title>
                  </v-col>
                  <v-col cols="12" lg="5" md="1" sm="6" xs="7">
                    <v-list-item-title  class="ListItem" v-text="item.total"></v-list-item-title>
                    <v-list-item-subtitle class="ListItem" >{{item.transaction}} Transactions</v-list-item-subtitle>
                  </v-col>
                  <v-divider></v-divider>
                </v-row>
              </v-list-item-content>
            </template>
          </v-list-item>
        </v-list>
      </v-tab-item>
    </v-tabs-items>
    <!-- <template class="text-xs-center mt-3">Current tab: {{model}}</template> -->
  </v-card>
</template>
<script>
import axios from "axios";
import { mapGetters } from "vuex";

const lhost = require('@/config/routehost.js').host;

export default {
  data() {
    return {
      active: "null",
      teste: "",
      teste1: "",
      month: "",
      months: [{ nome: "Novembro" }, { nome: "Dezembro" }, { nome: "Janeiro" }],
      stats: [],
      forecast: [
        {
          category: "Tuescategory",
          icon: "mdi-white-balance-sunny",
          total: "100"
        },
        {
          category: "1Wednescategory",
          icon: "mdi-white-balance-sunny",
          total: "100"
        },
        { category: "2Thurscategory", icon: "mdi-cloud", total: "200" },
        {
          category: "3Tuescategory",
          icon: "mdi-white-balance-sunny",
          total: "100"
        },
        {
          category: "4Wednescategory",
          icon: "mdi-white-balance-sunny",
          total: "100"
        },
        { category: "5Thurscategory", icon: "mdi-cloud", total: "200" }
      ],

      model: null
    };
  },
  computed: mapGetters(["getToken"]),

  mounted: function() {
    axios
      .get(lhost + "/users/statistics", {
        headers: { Authorization: "Bearer " + this.getToken }
      })
      .then(res => {
        this.stats = res.data.categories;

        console.log(this.stats);
      });
  },
  methods: {
    next() {
      this.teste = Number(this.model.split("-")[1]);

      switch (this.teste) {
        case 1:
          axios
            .get(lhost + "/users/statistics/date", {
              params: {
                begin: "0-11-2019"
              },
              headers: { Authorization: "Bearer " + this.getToken }
            })
            .then(res => {
              this.stats = res.data.categories;
            });
          break;
        case 2:
          axios
            .get(lhost + "/users/statistics/date", {
              params: {
                begin: "0-12-2019"
              },
              headers: { Authorization: "Bearer " + this.getToken }
            })
            .then(res => {
              this.stats = res.data.categories;
            });
          break;
        case 3:
          axios
            .get(lhost + "/users/statistics/date", {
              params: {
                begin: "0-1-2020"
              },
              headers: { Authorization: "Bearer " + this.getToken }
            })
            .then(res => {
              this.stats = res.data.categories;
            });
      }
    }
  }
};
</script>

<style scoped>
.ListItem {
  color: white !important;
}
</style>


