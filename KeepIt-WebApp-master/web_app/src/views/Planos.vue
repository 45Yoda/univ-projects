<template>
  <div>
    <!-- <div class="row">
          <div class="col-md-12 text-center">
            <h3 class="sidebar-panel">Escolha o plano que mais <br/> se adequa as suas necessidades</h3>
          </div>
        </div>

    -->
    <v-row class="text-sm-center">
      <v-col style="padding-top:0" cols="12" md="2">
        <Sidebar />
      </v-col>
      <v-col style="padding-top:1" class="justify-center" cols="12" md="10">
        <v-row style="padding-left:10%">
          <v-col class="text-xs-center" cols="12" md="5">
            <v-card width="350px" height="200px" class="sidebar-panel justify-lg-center " color="white">
              <v-card-title class="justify-center">
                <h4>Plano Básico</h4>
              </v-card-title>

              <v-card-text class = "text-center">
                <v-spacer></v-spacer>
              <p> Organize as suas faturas </p>
                  <v-spacer></v-spacer>
                  <br />
                <v-btn style=" margin-bottom: 20px;" color="#3bb3a9">
                Faça o seu registo gratuitamente
                <v-icon right dark>mdi-chevron-right</v-icon>
              </v-btn>
              </v-card-text>
            </v-card>
          </v-col>

          <v-col class="text-sm-center" cols="12" md="5">
            <v-card width="350px" height="200px" class="sidebar-panel" color="white">
              <v-card-title class="justify-center">
                <h4>Plano Premium</h4>
              </v-card-title>

              <v-card-text>
                Organize as suas faturas e obtenha diversas
                <br />estatísticas e funcionalidades
              </v-card-text>
              <br />
              <v-btn style=" margin-bottom: 20px;" color="#3bb3a9">
                Torne-se Premium
                <v-icon right dark>mdi-chevron-right</v-icon>
              </v-btn>
            </v-card>
          </v-col>
        </v-row>

        <v-col >
          <v-container>
          <v-row style="padding-left:10%">
            <v-col class="text-sm-center" max-width="100" cols="12" lg="12" md="12">
              <div>
                <v-expansion-panel-header style="background:#3CBDA9;color:white;maxWidth: 700px;">
                  <v-row>
                    <v-col cols="12" md="5">Features</v-col>
                    <v-col cols="12" md="4">Basic</v-col>
                    <v-col cols="12" md="3">Premium</v-col>
                  </v-row>
                </v-expansion-panel-header>

                <v-expansion-panels focusable style="maxWidth: 700px;">
                  <v-expansion-panel style="background:#3d3a3a;color:white">
                    <v-expansion-panel-header expand-icon="mdi-plus-circle">
                      <v-row>
                        <v-col cols="12" md="5">Organize as suas faturas</v-col>
                        <v-col cols="12" md="4">
                          <v-icon color="#46cba7">mdi-circle-slice-8</v-icon>
                        </v-col>
                        <v-col cols="12" md="3">
                          <v-icon color="#46cba7">mdi-circle-slice-8</v-icon>
                        </v-col>
                      </v-row>
                    </v-expansion-panel-header>
                    <v-expansion-panel-content
                      class="text-left"
                      style="background:#544f4e;color:white;font-size: 0.9em;"
                    >
                      <v-row>
                        <v-col cols="12" md="5">Visualize as suas faturas</v-col>
                        <v-col cols="12" md="4">
                          <v-icon color="#46cba7">mdi-circle-slice-8</v-icon>
                        </v-col>
                        <v-col cols="12" md="3">
                          <v-icon color="#46cba7">mdi-circle-slice-8</v-icon>
                        </v-col>
                      </v-row>
                    </v-expansion-panel-content>
                    <v-divider dark></v-divider>
                    <v-expansion-panel-content
                      class="text-left"
                      style="background:#544f4e;color:white;font-size:0.9em"
                    >
                      <v-row>
                        <v-col cols="12" md="5">Edite as suas faturas</v-col>
                        <v-col cols="12" md="4">
                          <v-icon color="#46cba7">mdi-circle-slice-8</v-icon>
                        </v-col>
                        <v-col cols="12" md="3">
                          <v-icon color="#46cba7">mdi-circle-slice-8</v-icon>
                        </v-col>
                      </v-row>
                    </v-expansion-panel-content>
                    <v-divider dark></v-divider>
                    <v-expansion-panel-content
                      class="text-left"
                      style="background:#544f4e;color:white;font-size:0.9em"
                    >
                      <v-row>
                        <v-col cols="12" md="5">Pesquise pelas suas faturas</v-col>
                        <v-col cols="12" md="4">
                          <v-icon color="#46cba7">mdi-circle-slice-8</v-icon>
                        </v-col>
                        <v-col cols="12" md="3">
                          <v-icon color="#46cba7">mdi-circle-slice-8</v-icon>
                        </v-col>
                      </v-row>
                    </v-expansion-panel-content>
                    <v-divider dark></v-divider>
                    <v-expansion-panel-content
                      class="text-left"
                      style="background:#544f4e;color:white;font-size:0.9em"
                    >
                      <v-row>
                        <v-col cols="12" md="5">Remova as suas faturas</v-col>
                        <v-col cols="12" md="4">
                          <v-icon color="#46cba7">mdi-circle-slice-8</v-icon>
                        </v-col>
                        <v-col cols="12" md="3">
                          <v-icon color="#46cba7">mdi-circle-slice-8</v-icon>
                        </v-col>
                      </v-row>
                    </v-expansion-panel-content>
                    <v-divider dark></v-divider>
                    <v-expansion-panel-content
                      class="text-left"
                      style="background:#544f4e;color:white;font-size:0.9em"
                    >
                      <v-row>
                        <v-col cols="12" md="5">Arquive as suas faturas</v-col>
                        <v-col cols="12" md="4">
                          <v-icon color="#46cba7">mdi-circle-slice-8</v-icon>
                        </v-col>
                        <v-col cols="12" md="3">
                          <v-icon color="#46cba7">mdi-circle-slice-8</v-icon>
                        </v-col>
                      </v-row>
                    </v-expansion-panel-content>
                  </v-expansion-panel>
                  <v-expansion-panel style="background:#3d3a3a;color:white">
                    <v-expansion-panel-header expand-icon="mdi-plus-circle">
                      <v-row>
                        <v-col cols="12" md="5">Partilhe as suas faturas</v-col>
                        <v-col cols="12" md="4">
                          <v-icon depressed color="#46cba7">mdi-circle-slice-4</v-icon>
                        </v-col>
                        <v-col cols="12" md="3">
                          <v-icon color="#46cba7">mdi-circle-slice-8</v-icon>
                        </v-col>
                      </v-row>
                    </v-expansion-panel-header>
                    <v-expansion-panel-content
                      class="text-left"
                      style="background:#544f4e;color:white;font-size:0.9em"
                    >
                      <v-row>
                        <v-col cols="12" md="5">Partilhe com uma pessoa</v-col>
                        <v-col cols="12" md="4">
                          <v-icon color="#46cba7">mdi-circle-slice-8</v-icon>
                        </v-col>
                        <v-col cols="12" md="3">
                          <v-icon color="#46cba7">mdi-circle-slice-8</v-icon>
                        </v-col>
                      </v-row>
                    </v-expansion-panel-content>
                    <v-divider dark></v-divider>
                    <v-expansion-panel-content
                      class="text-left"
                      style="background:#544f4e;color:white;font-size:0.9em"
                    >
                      <v-row>
                        <v-col cols="12" md="5">Partilhe com um grupo de pessoas</v-col>
                        <v-col cols="12" md="4">
                          <v-icon color="white">mdi-circle-outline</v-icon>
                        </v-col>
                        <v-col cols="12" md="3">
                          <v-icon color="#46cba7">mdi-circle-slice-8</v-icon>
                        </v-col>
                      </v-row>
                    </v-expansion-panel-content>
                  </v-expansion-panel>
                  <v-expansion-panel style="background:#3d3a3a;color:white">
                    <v-expansion-panel-header expand-icon="mdi-plus-circle">
                      <v-row>
                        <v-col cols="12" md="5">Veja as suas estatísticas</v-col>
                        <v-col cols="12" md="4">
                          <v-icon depressed color="#46cba7">mdi-circle-slice-4</v-icon>
                        </v-col>
                        <v-col cols="12" md="3">
                          <v-icon color="#46cba7">mdi-circle-slice-8</v-icon>
                        </v-col>
                      </v-row>
                    </v-expansion-panel-header>
                    <v-expansion-panel-content
                      class="text-left"
                      style="background:#544f4e;color:white;font-size:0.9em"
                    >
                      <v-row>
                        <v-col cols="12" md="5">Visualize as estatísticas em forma de gráfico</v-col>
                        <v-col cols="12" md="4">
                          <v-icon color="#46cba7">mdi-circle-slice-8</v-icon>
                        </v-col>
                        <v-col cols="12" md="3">
                          <v-icon color="#46cba7">mdi-circle-slice-8</v-icon>
                        </v-col>
                      </v-row>
                    </v-expansion-panel-content>
                    <v-divider dark></v-divider>
                    <v-expansion-panel-content
                      class="text-left"
                      style="background:#544f4e;color:white;font-size:0.9em"
                    >
                      <v-row>
                        <v-col cols="12" md="5">Veja o número de transações num espaço de tempo</v-col>
                        <v-col cols="12" md="4">
                          <v-icon color="white">mdi-circle-outline</v-icon>
                        </v-col>
                        <v-col cols="12" md="3">
                          <v-icon color="#46cba7">mdi-circle-slice-8</v-icon>
                        </v-col>
                      </v-row>
                    </v-expansion-panel-content>
                    <v-expansion-panel-content
                      class="text-left"
                      style="background:#544f4e;color:white;font-size:0.9em"
                    >
                      <v-row>
                        <v-col cols="12" md="5">Visualize as estatísticas em forma de gráfico</v-col>
                        <v-col cols="12" md="4">
                          <v-icon color="#46cba7">mdi-circle-slice-8</v-icon>
                        </v-col>
                        <v-col cols="12" md="3">
                          <v-icon color="#46cba7">mdi-circle-slice-8</v-icon>
                        </v-col>
                      </v-row>
                    </v-expansion-panel-content>
                  </v-expansion-panel>
                </v-expansion-panels>
              </div>
            </v-col>
          </v-row>
          </v-container>
        </v-col>
      </v-col>
    </v-row>
    <!-- teste! Perguntar ao camal-->
  </div>
</template>

<script>

import Sidebar from "../components/Sidebar";



export default {
  components: {
    Sidebar
  }
};
</script>

<style>
.sidebar-panel {
  margin-left: 15px;
  margin-right: 15px;
  margin-bottom: 15px;
  margin-top: 100px;
  border-radius: 500px;
  justify-content: center;
}
</style>
