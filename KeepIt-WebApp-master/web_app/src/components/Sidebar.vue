<template>
  <v-navigation-drawer  color="#314E4A" dark absolute v-model="drawer" :mini-variant.sync="mini" permanent>
    <v-list-item>
      <v-list-item-avatar>
        <v-img src="https://avatars2.githubusercontent.com/u/17687234?s=400&v=4"></v-img>
      </v-list-item-avatar>

      <v-list-item-title>{{UserName}}</v-list-item-title>

      <v-btn icon to="/profile">
        <v-icon>mdi-wrench</v-icon>
      </v-btn>

      <v-btn small icon @click.stop="mini = !mini">
        <v-icon>mdi-chevron-left</v-icon>
      </v-btn>
    </v-list-item>
    <v-divider style="margin: 5%"></v-divider>

    <v-list light color="#3bb3a9">
       <v-subheader class="text-center" v-if="!mini" inset>Home</v-subheader>
      <v-list-item v-for="item in items" :key="item.title" :to="item.link" link>
        <v-list-item-icon >
          <v-icon>{{ item.icon }}</v-icon>
        </v-list-item-icon>

        <v-list-item-content>
          <v-list-item-title>{{ item.title }}</v-list-item-title>
        </v-list-item-content>
      </v-list-item>
    </v-list>

    <v-divider style="margin: 5%"></v-divider>

    <v-list light color="#3bb3a9">
       <v-subheader  class="text-center" v-if="!mini" inset>Suporte</v-subheader>
       <v-list-item v-for="sup in sups" :key="sup.title" :to="sup.link" link>
        <v-list-item-icon >
          <v-icon>{{ sup.icon }}</v-icon>
        </v-list-item-icon>

        <v-list-item-content>
          <v-list-item-title>{{ sup.title }}</v-list-item-title>
        </v-list-item-content>
      </v-list-item>
    </v-list>

     <div class="footer">
      <v-footer dark inset class="pa-3" color="#314E4A">
        <div>
          KeepIt
          <v-icon small>mdi-heart-outline</v-icon>
          {{new Date().getFullYear()}}
        </div>
      </v-footer>
    </div>

  </v-navigation-drawer>
</template>

<script>
import axios from "axios";
import { mapGetters } from "vuex";

const lhost = require('@/config/routehost.js').host;

export default {
  data: () => ({
    drawer: true,
    items: [
      // mdi-home-city
      { title: "Faturas", icon: "mdi-script", link:"/dashboard" },
      { title: "Consultar Estatisticas", icon:"mdi-chart-pie", link:"/stats"},
      { title: "Planos", icon:"mdi-cards-heart", link:"/planos" },
    ],
    sups: [
      // mdi-home-city
      { title: "FAQ", icon: "mdi-help", link:"/faq" },
      { title: "Apoio Técnico", icon:"mdi-tooltip", link:"/apoio"},
      { title: "About", icon:"mdi-lightbulb", link:"/about" },
    ],
    mini: true,
    UserName: "",
    Home: "Estatísticas"
  }),
  computed: mapGetters(["getToken"]),
  methods: {
    //...mapMutations(["setName"]),
  },
  mounted: function() {
    axios
      .get(lhost + "/users", {
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

.footer {
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
