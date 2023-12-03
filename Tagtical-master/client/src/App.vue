<template>
  <div id="app">
    <v-app>
      <Header/>
      <v-content class="colored">
        <router-view/>
      </v-content>
    </v-app>
    <v-footer class="pa-3" color="#c8ebdf">
      <v-spacer></v-spacer>
      <div> BitBear &copy; {{ new Date().getFullYear() }}</div>
  </v-footer>
  </div>
</template>

<script>
import Header from "./components/layout/Header";
export default {
  name: "app",
  components: {
    Header
  }
};

//background: rgba(21, 101, 136, 0.7);
</script>


<style>

.colored {
  font-family: Arial, Helvetica, sans-serif;
  line-height: 1.4;
  background: #c8ebdf;
  box-sizing: border-box;
  margin: 0;
  padding: 0;
}

.btn {
  display: inline-blcok;
  border: none;
  background: #379683;
  color: #fff;
  padding: 7px 20px;
  cursor: pointer;
}
.btn:hover {
  background: #d35f3b;
}
</style>