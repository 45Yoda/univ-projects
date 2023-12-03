<template>
  <div>
          <v-list-tile @click="$emit('go-game',event._id)">
            <v-list-tile-action>
              <v-icon>public</v-icon>
            </v-list-tile-action>
            <v-list-tile-content>
              <v-list-tile-title>
                {{event.teamA.name + ' vs ' + event.teamB.name}}
                
              </v-list-tile-title>
              <v-subheader style="padding-left:0px;">
                {{event.date}}
              </v-subheader>
            </v-list-tile-content>
          </v-list-tile>

  </div>
</template>

<script>
export default {
  name: "EventItem",
  props: ["event"]
};

/*
<div class="text-xs-center">

      <v-btn @click="$emit('go-game', event._id)" block class="event" >
          
          {{event.teamA.name + ' vs ' + event.teamB.name}} 
          {{event.date}}
      </v-btn>


      
      </div>
*/
</script>

<style scoped>


.event {
  color: #070707;
  padding: 10px;
  border-bottom: 1px #ccc dotted;
  text-align: center;
  font-size: 14px;
}

.del {
  background: #ff0000;
  color: #fff;
  border: none;
  padding: 5px 10px;
  border-radius: 50%;
  cursor: pointer;
  float: right;
}
</style>
