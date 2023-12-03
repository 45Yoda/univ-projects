<template>
  <div>
    <v-app-bar app src="../assets/app.png" color="deep-purple accent-4">
      <!-- <v-app-bar-nav-icon></v-app-bar-nav-icon> -->
      <router-link v-if="loggedIn" to="/dashboard">
        <v-img
          alt="Logo"
          class="shrink mr-2"
          contain
          src="../assets/kitheader.png"
          transition="scale-transition"
          width="40"
        />
      </router-link>
      <router-link v-else to="/">
        <v-img
          alt="Logo"
          class="shrink mr-2"
          contain
          src="../assets/kitheader.png"
          transition="scale-transition"
          width="40"
        />
      </router-link>

      <router-link class="toolbar-title" v-if="loggedIn" to="/dashboard">
        <v-toolbar-title style="font-size:2em">KeepIt</v-toolbar-title>
      </router-link>

      <router-link class="toolbar-title" v-else to="/">
        <v-toolbar-title style="font-size:2em">KeepIt</v-toolbar-title>
      </router-link>

      <v-spacer></v-spacer>

      <v-btn @click="doLogout" v-if="loggedIn" text>
        <span>Sign Out</span>
        <v-icon>mdi-logout</v-icon>
      </v-btn>
      <v-btn v-else text to="/login">
        <span>Sign In</span>
        <v-icon>mdi-login</v-icon>
      </v-btn>
    </v-app-bar>
  </div>
</template>
<script type="text/javascript">
window.onbeforeunload = function() {
  return "Calling some alert messages here"; //return not alert
};
</script>
<script>
import { mapGetters, mapMutations } from "vuex";

export default {
  name: "Header",
  computed: mapGetters(["loggedIn"]),
  // created() {
  //   window.addEventListener("beforeunload", this.doLogout);
  // },
//   created() {
//     // does the browser support the Navigation Timing API?
//     if (window.performance) {
//         console.info("window.performance is supported");
//     }
//     // do something based on the navigation type...
//     if(performance.navigation.type === 0) {
//         console.info("TYPE_RELOAD");
//         this.doLogout();
//     }
// },
  methods: {
    ...mapMutations(["removeToken"]),

    doLogout() {
      localStorage.removeItem("access_token");
      this.removeToken();
      this.$router.push("/");
    }
  }
};
</script>

<style scoped>
.toolbar-title {
  color: inherit;
  text-decoration: inherit;
}
</style>
