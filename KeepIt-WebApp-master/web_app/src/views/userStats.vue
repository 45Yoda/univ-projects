<template>
  <div>
    <v-row>
      <v-col cols="4" lg="2">
        <Sidebar />
      </v-col>
    </v-row>
    <!-- <v-row style="padding-left:15%; padding-right: 5%" > -->
    <v-row style="padding-left:10%; padding-right: 5%">
      <v-col cols="12" lg="8" md="8" sm="12" xs="12" xl="9">
        <pieChart :datacollection1="datacollection1" />
      </v-col>

      <v-col cols="12" lg="4" md="4" sm="12" xs="12" xl="3">
        <statCat />
        <!-- <div id="app">
       <PDFDocument v-bind="{url, scale}" />
        </div>-->
      </v-col>
    </v-row>
  </div>
</template>

<script>
import { mapGetters } from "vuex";

import axios from "axios";
import Sidebar from "../components/Sidebar";
import pieChart from "../components/stats/statCharts";
import statCat from "../components/stats/statCategory";

const lhost = require('@/config/routehost.js').host;

export default {
  data() {
    return {
      url: "../js/pdf.pdf", // a PDF
      scale: 2,
      meses: [],
      mesesM: [],
      labelss: [],
      colors:[],
      colorsOpa: [],
      categCor: [
        {
          Category: "Saúde",
          Color: "rgb(255,0,0)",
          ColorOpa: "rgba(255,0,0,0.5)"
        },
        {
          Category: "Despesas Gerais",
          Color: "rgb(0,0,255)",
          ColorOpa: "rgba(0,0,255,0.5)"
        },
        {
          Category: "Educação",
          Color: "rgb(255, 152, 0)",
          ColorOpa: "rgba(255, 152, 0,0.5)"
        },
        {
          Category: "Transportes",
          Color: "rgb(255, 255, 0)",
          ColorOpa: "rgba(255, 255, 0,0.5)"
        },
        {
          Category: "Serviços",
          Color: "rgb(233,30,99)",
          ColorOpa: "rgba(233,30,99,0.5)"
        },
        {
          Category: "Restauração",
          Color: "rgb(0,255,0)",
          ColorOpa:"rgba(0, 255, 0,0.5)"
        },
        {
          Category: "Outros",
          Color: "rgb(156, 39, 176)",
          ColorOpa: "rgba(156, 39, 176,0.5)"
        }
      ],
      datacollection1: {
        labels: [],
        datasets: [
          {
            borderColor: "black",
            backgroundColor: [],
            data: []
          }
        ]
      }
    };
  },
  computed: mapGetters(["getToken"]),

 async mounted() {
    await axios
      .get(lhost + "/users/statistics/date", {
        params: {
          begin: "0-11-2019"
        },
        headers: { Authorization: "Bearer " + this.getToken }
      })
      .then(res => {
        for (var i = 0, m = 0; i < res.data.categories.length; i++) {
          if (res.data.categories[i].total != 0) {
            this.meses[m] = res.data.categories[i].total;
            this.mesesM[m] = res.data.categories[i].monthly_mean;
            this.labelss[m] = res.data.categories[i].category;
            this.colors[m] = this.findValueByKey(
              this.categCor,
              res.data.categories[i].category
            );
            this.colorsOpa[m] = this.findValueByKey2(
              this.categCor,
              res.data.categories[i].category
            );
            m++;

          }
        }

        console.log(this.colors);
        //   })
        //   axios
        //     .get(lhost + "/users/statistics/date", {
        //       params: {
        //         begin: "0-11-2019"
        //       },
        //       headers: { Authorization: "Bearer " + this.getToken }
        //     })
        //     .then(res => {
        //        for (var i = 0; i < res.data.categories.length; i++) {
        //       this.meses[i] = res.data.categories[i].total;
        //       this.labelss[i] = res.data.categories[i].category;
        //     }
        //     });
        // axios
        //   .get(lhost + "/users/statistics/date", {
        //     params: {
        //       begin: "0-12-2019"
        //     },
        //     headers: { Authorization: "Bearer " + this.getToken }
        //   })
        //   .then(res => {
        //     this.meses.push(res.data.total);

        this.datacollection1 = {
          labels: this.labelss,
          datasets: [
            {
              label: "Valor gasto neste mês",
              backgroundColor: this.colors,
              // backgroundColor: [
              //   "rgb(255,0,0)",
              //   "rgb(0,255,0)",
              //   "rgb(0,0,255)",
              //   "rgb(255, 152, 0)",
              //   "rgb(255, 255, 0)",
              //   "rgb(156, 39, 176)",
              //   "rgb(233,30,99)"
              // ],

              borderColor: "black",
              pointBackgroundColor: "rgba(171, 71, 188, 1)",
              data: this.meses
            },
            {
              label: "Média de gasto mensal",
              backgroundColor: this.colorsOpa,
              // backgroundColor: [
              //   "rgba(255,0,0,0.5)",
              //   "rgba(0,255,0,0.5)",
              //   "rgba(0,0,255,0.5)",
              //   "rgba(255, 152, 0,0.5)",
              //   "rgba(255, 255, 0,0.5)",
              //   "rgba(156, 39, 176,0.5)",
              //   "rgba(233,30,99,0.5)"
              // ],

              borderColor: "black",
              pointBackgroundColor: "rgba(171, 71, 188, 1)",
              data: this.mesesM
            }
          ]
        };
      });
       await  axios
        .get(lhost + "/users/update", {
          headers: { Authorization: "Bearer " + this.getToken }
        })
        .then(()=> {
        });
  },
  components: {
    Sidebar,
    pieChart,
    statCat
    // PDFDocument,
    // pdf
  },
  methods: {
    findValueByKey: function(opts, key) {
      var match = opts.filter(function(opt) {
        return opt.Category === key;
      });
      return match[0] ? match[0].Color : null;
    },
    findValueByKey2: function(opts, key) {
      var match = opts.filter(function(opt) {
        return opt.Category === key;
      });
      return match[0] ? match[0].ColorOpa : null;
    }
  }
};
</script>


<style>
* {
  text-transform: none !important;
}
</style>