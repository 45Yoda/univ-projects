<template>
      <v-container style="padding-top:0px" fluid>
        <v-row style="background-color:#618f88">
          <!-- <v-col cols="12" class="text-center">
        <h1>Welcome to KeepIt!</h1>
          </v-col>-->
          <v-img contain height="600px" width="940px" src="../assets/banner.png"></v-img>
        </v-row>

        <div style="background-color:#618f88; margin: -12px; padding: 12px;">
          <v-row align="center" justify="center">
            <h1>Keep your receipts organized with no hassle</h1>
          </v-row>
          <v-row>
            <v-col cols="12" lg="4" md="4" justify="center">
              <v-card align="center" justify="center" color="#3CBDA9" min-height="146px">
                <v-card-title class="justify-center">Organize</v-card-title>
                <v-card-text>Easily organize all your receipts in the app. No more annoying paper needed!</v-card-text>
              </v-card>
            </v-col>

            <v-col cols="12" lg="4" md="4" justify="center">
              <v-card align="center" justify="center" color="#3CBDA9" min-height="146px">
                <v-card-title class="justify-center">Manage</v-card-title>
                <v-card-text>Search for a specific receipt or look at all the receipts in one of the pre-made categories!</v-card-text>
              </v-card>
            </v-col>

            <v-col cols="12" lg="4" md="4" justify="center">
              <v-card align="center" justify="center" color="#3CBDA9" min-height="146px">
                <v-card-title class="justify-center">Budget</v-card-title>
                <v-card-text>Look at monthly statistics and discover how much you spend in each category!</v-card-text>
              </v-card>
            </v-col>
          </v-row>
        </div>
        <div style="padding: 5%">
          <v-row align="center" justify="center">
            <h1>Let's Get Started!</h1>
          </v-row>
          <v-row>
            <v-col cols="12" lg="3" md="6" sm="12" xs="12">
              <v-card align="center" justify="center" color="#3CBDA9" min-height="200px">
                <v-avatar>
                  <img src="../assets/kitheader.png" alt="KIT" />
                </v-avatar>
                <v-card-title class="justify-center">Sign Up</v-card-title>
                <v-card-text>Create a free account and choose the plan that you want.</v-card-text>
              </v-card>
            </v-col>
            <v-col cols="12" lg="3" md="6" sm="12" xs="12">
              <v-card align="center" justify="center" color="#3CBDA9" min-height="200px">
                <v-avatar color="indigo">
                  <v-icon dark>mdi-inbox</v-icon>
                </v-avatar>
                <v-card-title class="justify-center">Add Receipts</v-card-title>
                <v-card-text>As soon as you buy something and the receipt drops in your inbox it appears in the app! No need to scan every receipt.</v-card-text>
              </v-card>
            </v-col>
            <v-col cols="12" lg="3" md="6" sm="12" xs="12">
              <v-card align="center" justify="center" color="#3CBDA9" min-height="200px">
                <v-avatar color="indigo">
                  <v-icon dark>mdi-book-multiple</v-icon>
                </v-avatar>
                <v-card-title class="justify-center">Manage Receipts</v-card-title>
                <v-card-text>Search for receipts using our filters or by using the pre-made categories.</v-card-text>
              </v-card>
            </v-col>

            <v-col cols="12" lg="3" md="6" sm="12" xs="12">
              <v-card align="center" justify="center" color="#3CBDA9" min-height="200px">
                <v-avatar color="indigo">
                  <v-icon dark>mdi-chart-line</v-icon>
                </v-avatar>

                <v-card-title class="justify-center">Look at your stats</v-card-title>
                <v-card-text>See where you spent your money by looking at the statistics tab.</v-card-text>
              </v-card>
            </v-col>
          </v-row>

          <v-row align="center" justify="center">
            <v-btn color="#3CBDA9" to="/register" v-if="!loggedIn">Create an Account</v-btn>
          </v-row>
        </div>
      </v-container>
</template>

<script>

import { mapGetters } from "vuex";

export default {
  computed: mapGetters(["loggedIn"])
};
</script>


<style scoped>
h1:hover {
  background-color: rgba(255, 255, 255, 0);
}
</style>