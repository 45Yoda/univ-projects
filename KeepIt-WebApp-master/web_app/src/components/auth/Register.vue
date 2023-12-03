<template>
  <v-row align="center" justify="center">
    <v-col class="login-form text-sm-center">
      <div class="display-1 mb-3">
        <v-icon dark mr-2 large>mdi-script</v-icon>
      </div>
      <v-card dark color="#314E4A" style="margin-bottom:10px">
        <v-card-title>
          <template>Sign UP to KeepIt</template>
        </v-card-title>
        <v-card-text class="subheading">
          <v-form ref="form" lazy-validation>
            <v-text-field
              :rules="[this.rules.basicRule]"
              v-model="name"
              prepend-icon="mdi-email"
              label="Name"
            />
            <v-text-field
              :rules="[this.rules.basicRule]"
              v-model="email"
              prepend-icon="mdi-email"
              label="Email"
              type="email"
            />
            <v-text-field
              :rules="[this.rules.basicRule]"
              v-model="keepemail"
              suffix="@keepit.pt"
              prepend-icon="mdi-email"
              label="KeepIt Email"
              type="email"
            />
            <v-text-field
              :rules="[this.rules.basicRule, this.rules.passRule]"
              v-model="password"
              prepend-icon="mdi-lock"
              label="Password"
              type="password"
            />
          </v-form>
          <v-alert dark v-model="alertOn" dense outlined type="error">{{msgerror}}</v-alert>
          <v-btn class="btn1" light block @click="register">Sign up</v-btn>
        </v-card-text>
      </v-card>

      <div style="color:white">
        Already have an account?
        <v-btn to="/login">Sign In</v-btn>
      </div>
    </v-col>
  </v-row>
</template>

<script>
import axios from "axios";

const lhost = require("@/config/routehost.js").host;

export default {
  data() {
    return {
      name: "",
      keepemail: "",
      email: "",
      password: "",
      msgerror: "",
      rules: {
        basicRule: value => !!value || "Required.",
        passRule: value =>
          value.length >= 4 || "Password to short. Use at least 4 caracters"
      },
      alertOn: false
    };
  },
  methods: {
    register() {
      axios
        .post(lhost + "/users/register", {
          name: this.name,
          email: this.email,
          keep_email: this.keepemail + "@keepit.pt",
          password: this.password,
          type: 1
        })
        .then(response => {
          console.log(" entrei" + response);

          if (response.data.status == "OK") {
            this.$router.push("/login");
          }
        })

        .catch(erro => {
          console.log(erro.response.data.status)
          if (erro.response.data.status == 'Email already in use') {
            console.log("tetas");
            this.alertOn = true;
            this.msgerror = "Email already in use!";
          } else {
             console.log("mamolas");
            this.alertOn = true;
            this.msgerror = "KeepIt Email already in use!";
          }
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