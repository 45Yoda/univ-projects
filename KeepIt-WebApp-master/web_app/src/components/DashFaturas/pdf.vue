<template>
  <div>
    <v-icon @click="closepdf">mdi-close</v-icon>
    <embed :src="link" width="430" height="500" type="application/pdf" />
  </div>
</template>

<script>
export default {
  props: ["link"],
  data() {
    return {
      //link: "http://www.africau.edu/images/default/sample.pdf"
    };
  },
  methods: {
    closepdf() {
      this.$emit("closepdf", "false");
    }
  }
};
</script>