<template>
  <div>
    <v-container fluid grid-list-xl >
    <v-layout row justify-center>
      <v-flex xs4>
        <HeatMap v-bind:gamedata="team" parte='First Half'/>
      </v-flex>
      <v-flex xs1>
      </v-flex>
      <v-flex xs4>
        <HeatMap v-bind:gamedata="team" parte='Second Half'/>
      </v-flex>
    </v-layout>
  </v-container>
    <SingleEvent v-bind:gamedata="team" v-bind:gameid="idG" v-on:view-game="viewGame"/>
  </div>
</template>


<script>
import SingleEvent from "../components/SingleEvent";
import HeatMap from "../components/HeatMap";
import axios from 'axios';
import Sidebar from "../components/Sidebar";

export default {
  name: "Team",
  components: {
    SingleEvent,
    HeatMap
  },
  data(){
    return {
      team: [],
      idG: "",
    }
  },
  methods: {
    viewGame(id) {
      window.open("http://localhost:5000/files/" + id + "/sh.html");
    }
  },
  
  created(){
    var id = this.$route.params.id;
    this.idG = id;
    var t;
    if (this.$route.params.team=='A')
      t="teamA"
    else t="teamB"
    axios
      .get(`http://localhost:5000/api/games/${id}/${t}`)
      .then(res => (this.team = res.data))
      .catch(err => console.log(err));
  }
};
</script>


