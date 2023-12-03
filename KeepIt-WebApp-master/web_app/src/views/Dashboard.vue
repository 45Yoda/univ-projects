<template>
  <div>
    <v-row>
      <v-col cols="12" lg="1">
        <Sidebar />
      </v-col>
      <!-- <v-row style="padding-left:15%; padding-right: 5%" > -->
      <v-col cols="12" lg="7" md="6" sm="12" xs="12">
        <Faturas @showfatura="onfatura" @sendlink="getlink" />
      </v-col>
      <v-col cols="12" lg="3" md="6" sm="12" xs="12">
        <template v-if="this.value=='true'">
          <pdf :link="link" @closepdf="offatura"></pdf>
        </template>
        <!-- <div id="app">
       <PDFDocument v-bind="{url, scale}" />
        </div>-->
      </v-col>
    </v-row>
  </div>
</template>

<script>
import Sidebar from "../components/Sidebar";
//import Teste from "../components/Teste";
import Faturas from "../components/DashFaturas/Faturas";
import pdf from "../components/DashFaturas/pdf";
// import PDFDocument from "../components/PDFDocument";
//import pdfTeste from "../components/pdf/pdfteste.vue"

export default {
  data() {
    return {
      url: "../js/pdf.pdf", // a PDF
      value: "false",
      scale: 2,
      pdf: "",
      link: ""
    };
  },
  components: {
    Sidebar,
    //Teste,
    Faturas,
    pdf: pdf
    // PDFDocument,
  },
  methods: {
    getlink(valor) {
      this.link = valor;
    },
    onfatura(valor) {
      if (valor == "true") {
        this.value = valor;
      }
    },
    offatura(valor) {
      if (valor == "false") {
        this.value = valor;
      }
    }
  }
};
</script>


<style>
* {
  text-transform: none !important;
}
</style>