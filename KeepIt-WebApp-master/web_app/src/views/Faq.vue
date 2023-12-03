<template>
  <v-row>
    <v-col>
      <Sidebar></Sidebar>
    </v-col>

    <v-col>
      <v-container fluid>
        <v-row rows="12" align="center" justify="center">
          <v-img contain src="../assets/faq.png"></v-img>
        </v-row>

        <br />

        <v-row rows="12" align="center" justify="center">
          <h1>Frequently Asked Questions</h1>
        </v-row>

        <!-- como fazer dropdown? Questão seta drop Resposta -->
        <v-row rows="12" align="center" justify="center">
          <v-col cols="8">
            <v-expansion-panels accordion>
              <v-expansion-panel v-for="(item,i) in items" :key="i">
                <v-expansion-panel-header>{{item.header}}</v-expansion-panel-header>
                <v-expansion-panel-content>{{item.content}}</v-expansion-panel-content>
              </v-expansion-panel>
            </v-expansion-panels>
          </v-col>
        </v-row>
      </v-container>
    </v-col>
  </v-row>
</template>

<script>
import Sidebar from "../components/Sidebar";

export default {
  components: { Sidebar },
  data() {
    return {
      items: [
        {
          header: "Posso omitir categorias no gráfico?",
          content:
            "Sim! Para isso, basta clicar na categoria que desejas omitir na legenda acima do gráfico e esta vai desaparecer "
        },
        {
          header: "Posso controlar os meus gastos mensalmente?",
          content:
            "Sim podes! Na aba de estatísticas o botão no canto superior esquerdo deixa escolher o mês que desejas ver "
        },
        {
          header: "Como encontro faturas?",
          content:
            "No dashboard, possuis uma barra de pesquisa que te deixa procurar as tuas faturas! "
        },
        {
          header: "O que significam os símbolos na barra lateral?",
          content:
            "Clicando na barra lateral esta vai expandir e deixar-te ver mais informações das diferentes abas"
        },
        {
          header: "Como posso editar o meu perfil?",
          content:
            "Expandindo a barra lateral (clicando em cima), em cima ao lado da foto de perfil existe um icon de uma chave inglesa, clicando aí irás para a página de editar perfil"
        },
        {
          header: "Como posso contactar-vos em caso de um problema?",
          content:
            "Podes contactar-nos através do email riverlei.keepit@hotmail.com ou preenchendo o formulário na aba de suporte"
        },
        {
          header: "É possível ver as estatísticas entre determinadas datas?",
          content:
            "Sim claro! Na aba de estatísticas basta usar os dois filtros em cima do gráfico e escolher as datas no calendário que aparece quando clicas em cada um deles"
        },
        {
          header: "Como adiciono uma fatura manualmente?",
          content:
            "Na dashboard encontrarás um botão com um mais que te deixa adicionar a fatura manualmente na categoria que desejares."
        }
      ]
    };
  }
};
</script>