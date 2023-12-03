<template>
  <div>
    <v-row>
      <v-col style="padding-top:0" cols="12" lg="2" >
        <Sidebar />
      </v-col>
      <v-col cols="8" style="padding-left:15%" align="center" justify="center" >
        <Profile/>
      </v-col>
    </v-row>
 </div>
</template>

<script>
import Sidebar from "../components/Sidebar";
import Profile from "../components/editProfile";
//import teste from "../components/pdfteste"

export default {
    components: {
    Sidebar,
    Profile
//    teste
  }
}
</script>

