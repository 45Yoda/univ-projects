<template>
  <div>
   <v-layout row justify-center>
      <v-flex xs4>
        <HeatMapPlayer v-bind:gamedata="player" parte='First Half'/>
      </v-flex>
      <v-flex xs1>
      </v-flex>
      <v-flex xs4>
        <HeatMapPlayer v-bind:gamedata="player" parte='Second Half'/>
      </v-flex>
    </v-layout>
    <SinglePlayer align="center" v-bind:player="player"/>
  </div>
</template>


<script>
import SinglePlayer from "../components/SinglePlayer";
import HeatMapPlayer from "../components/HeatMapPlayer";
import axios from 'axios';
import Sidebar from "../components/Sidebar";

export default {
  name: "Team",
  components: {
    SinglePlayer,
    HeatMapPlayer
  },
  data(){
    return {
      player: []
    }
  },
  created(){
    var id = this.$route.params.id;
    var t;
    if (this.$route.params.team=='A')
      t="teamA"
    else t="teamB"
    var n = this.$route.params.n;
    axios
      .get(`http://localhost:5000/api/games/${id}/${t}/${n}`)
      .then(res => (this.player = res.data))
      .catch(err => console.log(err));
  }
};
</script>


