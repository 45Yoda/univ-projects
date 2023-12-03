import Vue from 'vue'
import './plugins/vuetify'
import App from './App.vue'
import router from './router'
import Vuetify from 'vuetify'
import 'vuetify/dist/vuetify.min.css'
import VueApexCharts from 'vue-apexcharts'


Vue.use(VueApexCharts)
Vue.use(Vuetify, {theme:false})

Vue.component('apexchart',VueApexCharts)
Vue.config.productionTip = false



new Vue({
  router,
  render: h => h(App)
}).$mount('#app')
