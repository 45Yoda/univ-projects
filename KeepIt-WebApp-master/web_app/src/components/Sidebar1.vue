<template>
  <v-navigation-drawer dark height="100%" permanent  color="#314E4A">
    <v-list>
      <v-list-item>
        <v-list-item-title>
          <v-avatar left style="padding-left:13%;padding-right:15%">
            <img src="https://avatars2.githubusercontent.com/u/17687234?s=400&v=4" />
          </v-avatar>
          <b>{{UserName}}</b>
        </v-list-item-title>
      </v-list-item>
      <v-row justify="center" align="center">
        <router-link class="toolbar-title" to="/profile">
          <v-btn depressed text>Edite o seu perfil</v-btn>
        </router-link>
      </v-row>
    </v-list>
    <v-divider></v-divider>

    <v-card-text>
      <b>Enjoy every feature by being a Premium member</b>
    </v-card-text>

    <!-- <v-row style="margin:-50%;padding-right:68%;padding-left:52%"> -->
    <v-card class="sidebar-panel" color="#3bb3a9">
      <v-card-title class="justify-center">
        <h4>Home</h4>
      </v-card-title>
      <v-card-text>
        <v-list>
          <v-list-item>
            <v-btn to="/dashboard" depressed color="#3bb3a9">
              <v-icon left>mdi-script</v-icon>
              <v-list-item-title>
                <b>Faturas</b>
              </v-list-item-title>
            </v-btn>
          </v-list-item>

          <v-list-item>
            <v-btn depressed color="#3bb3a9">
              <v-icon left>mdi-chart-pie</v-icon>
              <v-list-item-title>
                <b>
                  Consultar
                  <br />Estatísticas
                </b>
              </v-list-item-title>
            </v-btn>
          </v-list-item>

          <v-list-item>
            <v-btn to="/planos" depressed color="#3bb3a9">
              <v-icon left>mdi-cards-heart</v-icon>
              <v-list-item-title>
                <b>Planos</b>
              </v-list-item-title>
            </v-btn>
          </v-list-item>
        </v-list>
      </v-card-text>
    </v-card>
    <!-- </v-row> -->

    <!-- <v-row  style="margin:-5%;padding-right:23%;padding-left:9%"> -->
    <v-card class="sidebar-panel" color="#3bb3a9">
      <v-card-title class="justify-center">
        <h4>Suporte</h4>
      </v-card-title>
      <v-card-text>
        <v-list>
          <v-list-item>
            <v-btn depressed color="#3bb3a9">
              <v-icon left>mdi-help</v-icon>
              <v-list-item-title>
                <b>FAQ</b>
              </v-list-item-title>
            </v-btn>
          </v-list-item>

          <v-list-item>
            <v-btn depressed color="#3bb3a9">
              <v-icon left>mdi-wrench</v-icon>
              <v-list-item-title>
                <b>
                  Apoio
                  <br />Técnico
                </b>
              </v-list-item-title>
            </v-btn>
          </v-list-item>

          <v-list-item>
            <v-btn depressed color="#3bb3a9">
              <v-icon left>mdi-lightbulb</v-icon>
              <v-list-item-title>
                <b>Sugestões</b>
              </v-list-item-title>
            </v-btn>
          </v-list-item>
        </v-list>
      </v-card-text>
    </v-card>
    <!-- </v-row> -->
    <div class="footer">
      <v-footer class="pa-3" color="#314E4A">
        <div>
          KeepIt
          <v-icon small>mdi-heart-outline</v-icon>
          {{new Date().getFullYear()}}
        </div>
      </v-footer>
    </div>
  </v-navigation-drawer>

  <!-- <div class="sidebar">
        <div class="sidebar-panel"></div>
  </div>-->
</template>

<script>
import axios from "axios";
import { mapGetters } from "vuex";

export default {
  data: () => ({
    UserName: "",
    Home: "Estatísticas"
  }),
  computed: mapGetters(["getToken"]),
  methods: {
    //...mapMutations(["setName"]),
  },
  mounted: function() {
    axios
      .get("https://localhost:2014/users", {
        headers: { Authorization: "Bearer " + this.getToken }
      })
      .then(response => {
        this.UserName = response.data.name;
      });
  }
};
</script>


<style scoped>
.sidebar-panel {
  margin-left: 15px;
  margin-right: 15px;
  margin-bottom: 15px;
  border-radius: 500px;
}
.toolbar-title {
  color: inherit;
  text-decoration: inherit;
}


.footer{
    display: table;
    text-align: center;
    margin-left: auto;
    margin-right: auto;
}




p:hover,
h1:hover,
a:hover {
  background-color: rgba(255, 255, 255, 0.5);
}
</style>
