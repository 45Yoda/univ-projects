<template>
  <div>
    <link href="https://fonts.googleapis.com/css?family=Oxygen" rel="stylesheet">
    <link href="https://fonts.googleapis.com/css?family=Pacifico" rel="stylesheet">
    <div class="contain">
      <div class="overlay">
        <v-container>
          <v-layout row wrap>
            <v-flex class="inside">
              <h1 class="fonte">Welcome to Tagtical Hockey!</h1>
            </v-flex>
            <v-flex pa-5 align-center>
              <v-carousel delimiter-icon="fiber_manual_record" max="0px">
                <v-carousel-item v-for="(item,i) in items" :key="i" :src="item.src"></v-carousel-item>
              </v-carousel>
            </v-flex>
          </v-layout>
        </v-container>
      </div>
    </div>
    <div class="bar"></div>
    <br>
    <h1 align="center">Perfect for everyone</h1>
    <v-container>
      <v-layout row wrap>
        <v-flex xs6 sm4>
          <v-card
            min-height="384px"
            max-height="465px"
            elevation="10"
            class="text-xs-center ma-3"
            color="rgba(151, 201, 182,0.8)"
          >
            <v-card-text style="font-family:Pacifico,cursive;font-size:35px">Coaches</v-card-text>
            <v-responsive>
              <v-img :src="require('../assets/coach.png')"></v-img>
            </v-responsive>
            <v-card-text
              style="font-family:Oxygen, sans-serif; font-size:20px"
            >See what you need to make your team the best</v-card-text>
          </v-card>
        </v-flex>
        <v-flex xs6 sm4>
          <v-card
            min-height="384px"
            max-height="465px"
            elevation="10"
            class="text-xs-center ma-3"
            color="rgba(151, 201, 182,0.8)"
          >
            <v-card-text style="font-family:Pacifico,cursive;font-size:35px">Scouts</v-card-text>
            <v-responsive>
              <v-img max-height="300px" :src="require('../assets/scout.png')"></v-img>
            </v-responsive>
            <v-card-text
              style="font-family:Oxygen, sans-serif; font-size:20px"
            >Instantly know what players get into position better</v-card-text>
          </v-card>
        </v-flex>

        <v-flex xs6 sm4>
          <v-card
            min-height="384px"
            max-height="465px"
            elevation="10"
            class="text-xs-center ma-3"
            color="rgba(151, 201, 182,0.8)"
          >
            <v-card-text style="font-family:Pacifico,cursive;font-size:35px">Fans</v-card-text>
            <v-responsive>
              <v-img :src="require('../assets/fan.png')"></v-img>
            </v-responsive>
            <v-card-text
              style="font-family:Oxygen, sans-serif; font-size:20px"
            >Never miss a game from your favourite team again</v-card-text>
          </v-card>
        </v-flex>
      </v-layout>
    </v-container>
    <br>
    <br>
    <v-container grid-list-md>
      <v-layout class="text-xs-right" xs6>
        <v-flex>
          <img height="160px" width="250px"  src="../assets/tv.png">
        </v-flex>
        <v-flex xs6 class="text-xs-left">
          <h1>Watch the game!</h1>
          <p>
            Watch any game you might have missed from your favourite teams. Through the visualization page you can see 
            how the players moved during the game.
          </p>
        </v-flex>
      </v-layout>
      <v-layout class="text-xs-left" xs6>
        <v-flex xs6 class="text-xs-right">
          <h1>Perfect for coaches</h1>
          <p>
            Look at Heatmaps generated for your team to better understand their movement around the ring.
            Learn players' strengths and weaknesses through their statistics such as maximum velocity acceleration and distance traveled
          </p>
        </v-flex>
        <v-flex>
          <img height="160px" width="250px" src="../assets/tactic.png">
        </v-flex>
      </v-layout>
    </v-container>

    <div class="text-xs-center f2"> 
      <h1>Easily understand what is happening in the game and become the best with Tagtical Hockey</h1>
      <router-link class="btn2" to="/events" tag="button">Events</router-link>
    </div>
  </div>
</template>

<script>
export default {
  data() {
    return {
      items: [
        {
          src: require("../assets/hoq1.jpg")
        },
        {
          src: require("../assets/hoq2.jpg")
        },
        {
          src: require("../assets/hoq3.jpg")
        },
        {
          src: require("../assets/hoq4.jpg")
        }
      ]
    };
  }
};
//color="rgba(21, 150, 146,0.5)"
// v-card old color rgb(21, 101, 146,0.5)
</script>

<style scope>
.inside {
  position: relative;
  width: 100%;
  height: 100%;
  text-align: center;
  color: black;
}

.al {
  align-items: center;
  justify-content: center;
}

.f2 {
  font-family: "Oxygen", sans-serif;
  font-size: 20px
}

.btn2{
    display: inline-blcok;
    border: none;
    background: rgba(118, 191, 164,0.9);
    padding: 7px 20px;
    cursor: pointer;
  }
  .btn2:hover {
    background: rgba(118, 191, 164,0.5);
  }

.fonte {
  font-family: "Oxygen", sans-serif;
  font-size: 45px;
}

.overlay {
  width: 100%;
  height: 100%;
  background: rgba(173, 225, 205,0.7)
}

.contain {
  background-image: url("../assets/hoq3.jpg");
  background-size: cover;
}

.bar {
  width: 100%;
  height: 10px;
  background-color: #ffff;
  border: none;
}

.baixa {
  position: relative;
  width: 100%;
  height: 100%;
  padding-top: 100px;
  text-align: left;
}
</style>
