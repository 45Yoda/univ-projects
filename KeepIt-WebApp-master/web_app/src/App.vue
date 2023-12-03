<template>
  <div>
    <div id="app">
      <v-app class="colored">
        <Header />

        <v-content class="colored">
          <router-view />
        </v-content>
      </v-app>
    </div>
  </div>
</template>

<script>
import Header from "./components/Header";

export default {
  name: "App",

  components: {
    Header
  },

  data: () => ({
    //
  }),
  // mounted() {
  //   localStorage.clear();
  // }
};
</script>

<style scoped>
.colored {
  line-height: 1.4;
  background: #e9ebee;
  box-sizing: border-box;
  margin: 0;
  padding: 0;
}
</style>