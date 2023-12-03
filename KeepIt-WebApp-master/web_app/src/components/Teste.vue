<template>
  <v-card style="background-color:#3d3a3a" max-width="700" class="mx-auto">
    <v-toolbar color="#3cbda9" max-height="10px"></v-toolbar>

    <v-list dark two-line color="#3d3a3a">
      <v-subheader dark>
        Faturas
        <v-spacer></v-spacer>
        <v-btn icon>
          <v-icon>mdi-magnify</v-icon>
        </v-btn>

        <v-btn icon>
          <v-icon>mdi-checkbox-marked-circle</v-icon>
        </v-btn>
      </v-subheader>

      <v-list-item-group multiple active-class="blue--text">
        <template v-for="(fatura,index) in paginated">
          <v-list-item :key="fatura._id">
            <template v-slot:default="{ active, toggle }">
              <v-list-item-content>
                <v-row>
                  <v-col>
                    <v-list-item-title v-text="fatura.category"></v-list-item-title>
                  </v-col>
                  <v-col order="1">
                    <v-list-item-subtitle class="text--primary" v-text="fatura.total"></v-list-item-subtitle>
                  </v-col>
                  <v-col order="12">
                    <v-list-item-subtitle v-text="fatura.date"></v-list-item-subtitle>
                  </v-col>
                </v-row>
              </v-list-item-content>

              <v-list-item-action>
                <v-list-item-action-text v-text="fatura.total"></v-list-item-action-text>
                <v-icon v-if="!active">mdi-arrow-right</v-icon>

                <v-icon v-else color="yellow">mdi-star</v-icon>
              </v-list-item-action>
            </template>
          </v-list-item>

          <v-divider v-if="index + 1 < faturas.length" :key="index"></v-divider>
        </template>
      </v-list-item-group>
    </v-list>
    <div style="background-color:#3d3a3a" class="text-center">
      <v-pagination color="#3d3a3a" v-model="page" :length="pag_length"></v-pagination>
    </div>
  </v-card>
</template>

<script>
import { mapGetters } from "vuex";
import axios from "axios";

const lhost = require('@/config/routehost.js').host;

export default {
  data: () => ({
    page: 1,
    paginated: [],
    pag_length: 0,
    faturas: []
  }),
  computed: mapGetters(["getToken"]),
  mounted: function() {
    try {
      axios
        .get(lhost + "/receipts", {
          headers: { Authorization: "Bearer " + this.getToken }
        })
        .then(res => {
          if (res.data.status == "ERROR INVALID TOKEN") {
            localStorage.removeItem("access_token");
            this.removeToken();
            this.$router.push("/login");
          } else {
            this.faturas = res.data;
            this.pag_length = Math.ceil(this.faturas.length / 5);
            this.paginated = this.faturas.slice(0, 5);
          }
        })
        .catch(err => {
          console.log("Teste Error: " + err );
        });
    } catch (e) {
      return e;
    }
  },

  watch: {
    page: function(newPage) {
      let start = (newPage - 1) * 5;
      let end = start + 5;
      this.paginated = this.faturas.slice(start, end);
    }
  }
};
</script>
<style scoped>
.back-color {
  background-color: #59837d;
}
</style>
