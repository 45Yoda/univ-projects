<template>
  <div>
    <Sidebar v-bind:gamedata="gamedata"/>
    <h1 align="center" class="fonte">{{gamedata.teamA.name}} vs {{gamedata.teamB.name}}</h1>
   <router-view :key="$route.fullPath"></router-view>
   </div>
</template>

<script>
import axios from "axios";
import Sidebar from "../components/Sidebar";
export default {
  name: "Single",
  components: {
    Sidebar
  },
  data() {
    return {
      gamedata: [],
      watch: {
        gamedata() {
          return this.gamedata;
        }
      }
    };
  },
  methods: {
    viewGame(id) {
      window.open("http://localhost:5000/files/" + id + "/sh.html");
    }
  },
  created() {
    var id = this.$route.params.id;
    axios
      .get(`http://localhost:5000/api/games/${id}`)
      .then(res => (this.gamedata = res.data))
      .catch(err => console.log(err));
  }
};
</script>

<style scope>
.fonte {
  font-family: "Oxygen", sans-serif;
  font-size: 45px;
}

.fonte {
  font-family: "Oxygen", sans-serif;
  font-size: 45px;
}
</style>
