<script>
import { Pie, mixins } from 'vue-chartjs'
const { reactiveProp, reactiveData } = mixins

export default {
  extends:Pie,
  mixins: [reactiveProp, reactiveData],
  props: {
    options: {
      type: Object,
      default: null
    }
  },

  mounted () {
    // this.chartData is created in the mixin.
    // If you want to pass options please create a local options object
    this.renderChart(this.chartData, this.options)
  }
}
</script>

