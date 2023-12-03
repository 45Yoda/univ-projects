<template>
  <div max-width="100px" max-height="200px">
    <v-row>
      <v-col cols="12" lg="1">
        <v-menu :close-on-content-click="false" offset-x>
          <template v-slot:activator="{ on: menu }">
            <v-tooltip bottom>
              <template v-slot:activator="{ on: tooltip }">
                <v-btn depressed dark v-on="{ ...tooltip, ...menu }">
                  <v-icon small depressed>mdi-calendar-month</v-icon>
                </v-btn>
              </template>
              <span>Compare os seus gastos mensais</span>
            </v-tooltip>
          </template>
          <v-list>
            <v-list-item @click.stop="getm(ite.month) " v-for="(ite, index) in months" :key="index">
              <v-list-item-title v-model="months.month">{{ ite.month }}</v-list-item-title>
            </v-list-item>
          </v-list>
        </v-menu>
      </v-col>
      <v-col cols="12" lg="8">
        <v-container>
          <v-row>
            <v-col cols="12" lg="5">
              <v-menu
                v-model="menu1"
                :close-on-content-click="false"
                transition="scale-transition"
                offset-y
                max-width="290px"
                min-width="290px"
              >
                <template v-slot:activator="{ on }">
                  <v-text-field
                    readonly
                    v-model="computedDateFormatted"
                    persistent-hint
                    prepend-icon="mdi-calendar"
                    v-on="on"
                  ></v-text-field>
                </template>
                <v-date-picker v-model="data" no-title @input="menu1 = false"></v-date-picker>
              </v-menu>
            </v-col>

            <v-col cols="12" lg="6">
              <v-menu
                v-model="menu2"
                :close-on-content-click="false"
                transition="scale-transition"
                offset-y
                max-width="290px"
                min-width="290px"
              >
                <template v-slot:activator="{ on }">
                  <v-text-field
                    readonly
                    v-model="computedDateFormattedd"
                    persistent-hint
                    prepend-icon="mdi-calendar"
                    v-on="on"
                  ></v-text-field>
                </template>
                <v-date-picker :show-current="false" v-model="date" no-title @input="menu2 = false"></v-date-picker>
              </v-menu>
            </v-col>
            <v-col cols="12" lg="1">
              <v-icon @click="getByDate">mdi-calendar-range</v-icon>
            </v-col>
          </v-row>
        </v-container>
      </v-col>
    </v-row>
    <v-card flat style="background-color: #e9ebee;">
      <v-card-title>Total gasto por Categoria</v-card-title>
      <PieChart :chartData="datacollection" :options="options"></PieChart>
    </v-card>

    <v-card style="background-color: white;margin-top:5%">
      <v-card-title>Gastos Mensais</v-card-title>
      <LineChart :chartData="datacollection1" :options="options1"></LineChart>
    </v-card>
    <template></template>
    <!-- <v-row>
        <v-col>
          <v-card class="mx-auto text-center" color="#3d3a3a" max-width="600">
            <v-card-text>
              <v-sheet color="rgba(0, 0, 0, .12)"></v-sheet>
            </v-card-text>

            <GChart type="LineChart" :data="chartData" :options="chartOptions" />

            <v-card-text>
              <div class="display-1 font-weight-thin">Gastos mensais</div>
            </v-card-text>

            <v-divider></v-divider>

            <v-card-actions class="justify-center">
              <v-btn block text>Go to Report</v-btn>
            </v-card-actions>
          </v-card>
        </v-col>
    </v-row>-->
  </div>
</template>

<script>
import axios from "axios";
import { mapGetters } from "vuex";
//import Chart from "vue-chartjs";
import LineChart from "../../charts/LineChart";
import PieChart from "../../charts/PieChart";

const lhost = require('@/config/routehost.js').host;

export default {
  components: {
    PieChart,
    LineChart
  },
  props: ["datacollection1"],
  data() {
    return {
      dates: ["2019-09-10", "2019-09-20"],
      menu1: false,
      menu2: false,
      data: null,
      dataa: null,
      datee: null,
      date: null,
      Outubro: null,
      // datacollection1: {
      //   labels: ["Outubro", "Novembro", "Dezembro"],
      //   datasets: [
      //     {
      //       borderColor: "black",
      //       backgroundColor: [],
      //       data: [0, 0, 0]
      //     }
      //   ]
      // },
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
          ColorOpa: "rgba(0, 255, 0,0.5)"
        },
        {
          Category: "Outros",
          Color: "rgb(156, 39, 176)",
          ColorOpa: "rgba(156, 39, 176,0.5)"
        }
      ],

      months: [
        { month: "Novembro" },
        { month: "Dezembro" },
        { month: "Janeiro" }
      ],
      Novembro: null,
      Dezembro: null,
      Janeiro: null,

      stats: [],
      lineTotal: [],
      category: [],
      total: [],
      categoryy: [],
      totall: [],
      colors: [],
      totalLM: [
        {
          Novembro: "",
          Dezembro: "",
          Janeiro : ""
        }
      ],
      totalM: [],
      options1: {
        legend: {
          display: false
        },
        scales: {
          yAxes: [
            {
              ticks: {
                beginAtZero: true
              },
              gridLines: {
                display: false
              }
            }
          ],
          xAxes: [
            {
              position: "top"
            }
          ]
        },
        responsive: true,
        maintainAspectRatio: false,
        height: 100,
        width: 100,
        pieceLabel: {
          mode: "percentage",
          precision: 1
        }
      },
      options: {
        legend: {
          position: "left"
        },
        elements: {
          arc: {
            width: 1000
          }
        },
        responsive: true,
        maintainAspectRatio: false,
        height: 100,
        width: 100,
        pieceLabel: {
          mode: "percentage",
          precision: 1
        }
      },
      datacollection: {
        labels: [],
        datasets: [
          {
            borderColor: "black",
            backgroundColor: [],
            data: []
          }
        ]
      }
      // datacollection1: {
      //   labels: ["Outubro", "Novembro", "Dezembro"],
      //   datasets: [
      //     {
      //       borderColor: "black",
      //       backgroundColor: [],
      //       data: [0, 0, 0]
      //     }
      //   ]
      // }
    };
  },

  computed: {
    computedDateFormatted() {
      return this.formatDate(this.data);
    },
    computedDateFormattedd() {
      return this.formatDate(this.date);
    },
    ...mapGetters(["getToken"])
  },
  watch: {
    date() {
      this.dateFormatted = this.formatDate(this.data);
    },
    datee() {
      this.dateFormatted = this.formatDate(this.date);
    }
  },

  mounted() {
    axios
      .get(lhost + "/users/statistics", {
        headers: { Authorization: "Bearer " + this.getToken }
      })
      .then(res => {
        this.stats = res.data.categories;

        for (var i = 0; i < this.stats.length; i++) {
          this.category[i] = this.stats[i].category;
          this.total[i] = this.stats[i].total;
          this.colors[i] = this.findValueByKey(
            this.categCor,
            res.data.categories[i].category
          );
        }
        this.datacollection = {
          labels: this.category,
          datasets: [
            {
              backgroundColor: this.colors,
              // [
              //   "rgb(255,0,0)",
              //   "rgb(0,255,0)",
              //   "rgb(0,0,255)",
              //   "rgb(255, 152, 0)",
              //   "rgb(255, 255, 0)",
              //   "rgb(156, 39, 176)",
              //   "rgb(233,30,99)"
              // ],
              data: this.total
            }
          ]
        };
      });
  },
  methods: {
    dateRangeText() {
      return this.dates.join(" ~ ");
    },
    findValueByKey: function(opts, key) {
      var match = opts.filter(function(opt) {
        return opt.Category === key;
      });
      return match[0] ? match[0].Color : null;
    },

    formatDate(date) {
      if (!date) return null;

      const [year, month, day] = date.split("-");
      return `${day}-${month}-${year}`;
    },
    parseDate(date) {
      if (!date) return null;

      const [month, day, year] = date.split("/");
      return `${year}-${month.padStart(2, "0")}-${day.padStart(2, "0")}`;
    },

    getByDate() {
      this.dataa = this.formatDate(this.data);
      this.datee = this.formatDate(this.date);

      axios
        .get(lhost + "/users/statistics/date", {
          params: {
            begin: this.dataa,
            end: this.datee
          },
          headers: { Authorization: "Bearer " + this.getToken }
        })
        .then(res => {
          console.log(res.data);
          this.stats = res.data.categories;

          for (var i = 0; i < this.stats.length; i++) {
            this.categoryy[i] = this.stats[i].category;
            this.totall[i] = this.stats[i].total;
          }

          this.datacollection = {
            labels: this.categoryy,
            datasets: [
              {
                backgroundColor: [
                  "rgb(255,0,0)",
                  "rgb(0,255,0)",
                  "rgb(0,0,255)",
                  "rgb(255, 152, 0)",
                  "rgb(255, 255, 0)",
                  "rgb(156, 39, 176)",
                  "rgb(233,30,99)"
                ],
                data: this.totall
              }
            ]
          };
        });
    },
    getm(m) {
      switch (m) {
        case "Novembro":
          axios
            .get(lhost + "/users/statistics/date", {
              params: {
                begin: "0-11-2019"
              },
              headers: { Authorization: "Bearer " + this.getToken }
            })
            .then(res => {
              this.stats = res.data.categories;
              console.log("ola pie month");
              console.log(this.stats);

              for (var i = 0; i < this.stats.length; i++) {
                this.category[i] = this.stats[i].category;
                this.totalM[i] = this.stats[i].total;
              }
              this.datacollection = {
                labels: this.category,
                datasets: [
                  {
                    backgroundColor: [
                      "rgba(255,0,0,0.8)",
                      "rgba(0,255,0,0.8)",
                      "rgba(0,0,255,0.8)",
                      "rgba(255, 152, 0,0.8)",
                      "rgba(255, 255, 0,0.8)",
                      "rgba(156, 39, 176,0.8)",
                      "rgba(233,30,99,0.8)"
                    ],
                    borderWidth: 3,

                    data: this.totalM
                  }
                ]
              };
            });
          break;
        case "Dezembro":
          axios
            .get(lhost + "/users/statistics/date", {
              params: {
                begin: "0-12-2019"
              },
              headers: { Authorization: "Bearer " + this.getToken }
            })
            .then(res => {
              this.stats = res.data.categories;

              for (var i = 0; i < this.stats.length; i++) {
                this.category[i] = this.stats[i].category;
                this.totalM[i] = this.stats[i].total;
              }
              this.datacollection = {
                labels: this.category,
                datasets: [
                  {
                    backgroundColor: [
                      "rgba(255,0,0,0.8)",
                      "rgba(0,255,0,0.8)",
                      "rgba(0,0,255,0.8)",
                      "rgba(255, 152, 0,0.8)",
                      "rgba(255, 255, 0,0.8)",
                      "rgba(156, 39, 176,0.8)",
                      "rgba(233,30,99,0.8)"
                    ],
                    borderWidth: 3,

                    data: this.totalM
                  }
                ]
              };
            });
          break;
        case "Janeiro":
          axios
            .get(lhost + "/users/statistics/date", {
              params: {
                begin: "0-1-2020"
              },
              headers: { Authorization: "Bearer " + this.getToken }
            })
            .then(res => {
              this.stats = res.data.categories;
              for (var i = 0; i < this.stats.length; i++) {
                this.category[i] = this.stats[i].category;
                this.totalM[i] = this.stats[i].total;
              }
              this.datacollection = {
                labels: this.category,
                datasets: [
                  {
                    backgroundColor: [
                      "rgba(255,0,0,0.8)",
                      "rgba(0,255,0,0.8)",
                      "rgba(0,0,255,0.8)",
                      "rgba(255, 152, 0,0.8)",
                      "rgba(255, 255, 0,0.8)",
                      "rgba(156, 39, 176,0.8)",
                      "rgba(233,30,99,0.8)"
                    ],
                    borderWidth: 0.5,

                    data: this.totalM
                  }
                ]
              };
            });
          break;
      }
    }
  }
};
</script>

<style>
LineChart#barChart {
  background-color: #ff0000;
}
.small {
  max-width: 600px;
  margin: 150px auto;
}
</style>
