<template>
  <div style="background:rgb(228, 245, 239)">
    <v-list class="pa-0">
      <v-list-tile>
        <v-list-tile-action>
          <v-icon>event</v-icon>
        </v-list-tile-action>
        <v-list-tile-content>
          <v-list-tile-title style="font-size:20px">Events</v-list-tile-title>
        </v-list-tile-content>
      </v-list-tile>
    </v-list>

    <v-divider></v-divider>

    <v-list two-line>
      <v-list-tile v-for="event in events" v-bind:key="event._id">
        <EventItem v-bind:event="event" v-on:go-game="$emit('go-game',event._id)"/>
      </v-list-tile>
    </v-list>
  </div>
</template>

<script>
import EventItem from "./EventItem.vue";

export default {
  name: "Events",
  components: {
    EventItem
  },
  props: ["events"]
};

/*
 <v-container fluid>
    <v-layout row>
      <v-flex>
 <div v-bind:key="event._id" v-for="event in events">
          <EventItem
            v-bind:event="event"
            v-on:go-game="$emit('go-game',event._id)"
          />
        </div>
          </v-flex>
    </v-layout>
  </v-container>
*/
</script>

<style scoped>
.menos {
  position: relative;
  padding-bottom: 0px;
  padding-top: 0px;
}
</style>
