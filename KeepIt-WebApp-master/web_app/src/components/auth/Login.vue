<template>
  <v-row align="center" justify="center">
    <v-col class="login-form text-sm-center">
      <div class="display-1 mb-3">
        <v-icon dark mr-2 large>mdi-script</v-icon>
      </div>
      <v-card dark color="#314E4A" style="margin-bottom:10px">
        <v-card-title>
          <template>Login to KeepIt</template>
        </v-card-title>
        <v-card-text class="subheading">
          <v-form>
            <v-text-field :rules="[this.rules.basicRule]" v-model="email" prepend-icon="mdi-email" label="Email" type="email" />
            <v-text-field
              :rules="[this.rules.basicRule, this.rules.passRule]"
              v-model="password"
              prepend-icon="mdi-lock"
              label="Password"
              type="password"
            />
            <v-checkbox v-model="shouldStayLoggedIn" label="Stay logged in?" hide-details />
            <v-btn class="btn1" light block @click="submit">Sign In</v-btn>
          </v-form>
        </v-card-text>
      </v-card>

      <div style="color:white">
        Don't have an account?
        <v-btn to="/register">Sign Up</v-btn>
      </div>
    </v-col>
  </v-row>
</template>

<script>
import axios from "axios";
import { mapMutations } from "vuex";

const lhost = require('@/config/routehost.js').host;

export default {
  data() {
    return {
      email: "",
      password: "",
      shouldStayLoggedIn: false,
      msgerror: "",
       rules: {
        basicRule: value => !!value || 'Required.',
        passRule: value => value.length >= 4 || "Password to short. Use at least 4 caracters"}
        ,
    };
  },
  methods: {
    ...mapMutations(["setToken"]),

    submit() {
      // console.log("entrei submit");
      axios
        .post(lhost+"/users/login", {
          email: this.email,
          password: this.password
        })
        .then(response => {
          switch (response.data.status) {
            case "OK LOGGED":
              if (this.shouldStayLoggedIn) {
                localStorage.setItem("access_token", response.data.token);
              }

              this.setToken(response.data.token);
              this.$router.push("/dashboard");
              // console.log("It's Done!", response.data.token)
              break;

            default:
              this.msgerror = "Authentication Failed! Invalid Credentials.";
              this.$router.push("/login");
              break;
          }
        })
        .catch(err => {
          console.log("ERRRRRRROOOO", err)
          this.$router.push("/notfound");
        });
    }
  }
};
</script>

<style scoped>
.login-form {
  max-width: 500px;
}

.btn1 {
  margin-top: 10px;
}

.subheading {
  font-size: 30px;
  font-weight: 400;
}
</style>