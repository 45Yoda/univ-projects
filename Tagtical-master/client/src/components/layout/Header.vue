<template>
  <nav>
    <v-toolbar app color="rgb(118, 191, 164)">
      <v-toolbar-side-icon @click="drawer = !drawer"></v-toolbar-side-icon>

      <v-spacer></v-spacer>
      <img src="../../assets/hok2.png" width="4%">
      <v-toolbar-title style="font-size:32px;margin-right:20px">
        <span>Tagtical Hockey</span>
      </v-toolbar-title>
      <img src="../../assets/hok1.png" width="4%">

      <v-spacer></v-spacer>
    </v-toolbar>

    <v-navigation-drawer v-model="drawer" mobile-break-point="10240" app style="background:rgb(228, 245, 239)">
      <v-list class="pa-0">
        <v-list-tile>
          <v-list-tile-action>
            <v-icon>dashboard</v-icon>
          </v-list-tile-action>
          <v-list-tile-content>
            <v-list-tile-title style="font-size:20px">Dashboard</v-list-tile-title>
          </v-list-tile-content>
        </v-list-tile>
      </v-list>
      <v-divider></v-divider>

      <v-list>
        <v-list-tile v-for="link in links" :key="link.text" router :to="link.route">
          <v-list-tile-action>
            <v-icon>{{link.icon}}</v-icon>
          </v-list-tile-action>
          <v-list-tile-content>
            <v-list-tile-title>{{link.text}}</v-list-tile-title>
          </v-list-tile-content>
        </v-list-tile>
      </v-list>
    </v-navigation-drawer>
  </nav>
</template>

<script>
export default {
  name: "Header",
  data() {
    return {
      drawer: false,
      links: [
        { icon: "home", text: "Home", route: "/" },
        { icon: "event_note", text: "Events", route: "/events" },
        { icon: "question_answer", text: "About", route: "/about" }
      ]
    };
  }
};
</script>

<style scoped>
  .let{
    color:white
  }
</style>


