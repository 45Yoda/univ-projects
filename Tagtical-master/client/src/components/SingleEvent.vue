<template>
  <v-container fluid grid-list-xl>
    <v-layout row justify-center>
      <v-flex xs2>
        <v-btn @click="$emit('view-game', gameid)" v-bind:key="gameid" >Watch Game!</v-btn>
      </v-flex>
    </v-layout>
    <v-layout row justify-center>
      <v-flex xs4>
        <v-card height=auto width=500 style="background:rgb(228, 245, 239); position:relative; left:-30px" xs6 >
          <v-card-text>
            <table style="width:100%; height:40%" border="1" >
              <tr>
                <th>{{gamedata.name}}</th>
                <th>Maximum Velocity (m/s)</th>
                <th>Average Velocity (m/s)</th>
                <th>Distance (m)</th>
              </tr>
              <tr v-for="(player,index) in this.gamedata.players" :key="index">
                <td align="center">
                  {{gamedata.players[index].name}} </td>
                <td align="center">
                  {{gamedata.players[index].data.vel_max}} </td>
                <td align="center"> 
                  {{gamedata.players[index].data.vel_media}} </td>
                <td align="center"> 
                  {{gamedata.players[index].data.dist}} </td>
              </tr>
              <tr>
                <td align="center"><b> TOTAL</b></td>
                <td align="center"><b>{{this.velMax()}}</b></td>
                <td align="center"><b>{{this.velMedia()}}</b></td>
                <td align="center"><b>{{this.distTotal()}}</b></td>
              </tr>
            </table>
          </v-card-text>
        </v-card>
      </v-flex>
    </v-layout>
  </v-container>
</template>
 

<script>
export default {
  name: "SingleEvent",
  props: ["gamedata","gameid"],
  methods: {
    distTotal(){
      var distancia=0;
      for(var i = 0; i < this.gamedata.players.length;i++) 
        distancia+= this.gamedata.players[i].data.dist;
      return distancia.toFixed(2);
    },
    velMedia(){
      var media=0;
      for(var i = 0; i < this.gamedata.players.length;i++) 
        media+= this.gamedata.players[i].data.vel_media;
      return (media/this.gamedata.players.length).toFixed(2);
    },
    velMax(){
      var max=0;
      for(var i = 0; i < this.gamedata.players.length;i++) 
        if(this.gamedata.players[i].data.vel_max>max) 
          max = this.gamedata.players[i].data.vel_max;
      return max;
    }
  },
  watch: { 
    gamedata(){ 
      return this.gamedata;
      } 
    } 

};


</script>

