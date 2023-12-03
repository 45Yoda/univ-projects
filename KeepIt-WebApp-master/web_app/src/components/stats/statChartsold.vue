<template>
  <v-container>
    <div>
      <v-row>
        <v-col cols="12">
          <v-card style="background-color:#3d3a3a" max-width="700" class="mx-auto">
            <v-toolbar color="#3cbda9" max-height="10px">
              <v-toolbar-title>Intensity per Scan</v-toolbar-title>
              <v-spacer></v-spacer>
            </v-toolbar>
            <GChart type="PieChart" :data="chartData1" :options="chartOptions1" />
          </v-card>
        </v-col>
      </v-row>
      <v-row>
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
      </v-row>
    </div>
  </v-container>
</template>

<script>
import { GChart } from "vue-google-charts";

export default {
  data() {
    return {
      chartData: [
        ["Month", ""],
        ["Set", 1000],
        ["Out", 1170],
        ["Nov", 660],
        ["Dec", 1030]
      ],
      chartOptions: {
        axes: {
          x: {
            0: { side: "top" }
          }
        },
        legend: { position: "none" },
        vAxis: {
          textPosition: "none",
          gridlines: {
            color: "transparent"
          }
        },
        hAxis: {
          gridlines: {
            count: 6,
            color: "black"
          }
        },
        backgroundColor: "#555252",
        axisTitlesPosition: "none",
        chart: {
          title: "Company Performance",
          subtitle: "Sales, Expenses, and Profit: 2014-2017"
        }
      },
      // Array will be automatically processed with visualization.arrayToDataTable function
      chartData1: [
        ["Year", "Sales", "Expenses", "Profit"],
        [2014, 1000, 400, 200],
        [2015, 1170, 460, 250],
        [2016, 660, 1120, 300],
        [2017, 1030, 540, 350]
      ],
      chartOptions1: {
        backgroundColor: "#555252",
        chart: {
          title: "Pie Chart"
        },
         width: 700,
        height: 300,
      }
    };
  },
  components: {
    GChart
  }
};
</script>