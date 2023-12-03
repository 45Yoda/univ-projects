<template>
<div >
     <p>{{this.gamedata.name}}: {{this.parte}}</p>
     <apexchart v-if="gamedata" width="500" type="heatmap" :options="chartOptions" :series="series"></apexchart>
   </div>
</template>

<script>
export default {
    name: "HeatMap",
    props: ["gamedata","parte"],
    data: function() {
      return {
        teamdata: [[0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0],
                   [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0],
                   [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0],
                   [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0],
                   [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0],
                   [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0],
                   [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0],
                   [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0],
                   [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0],
                   [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0],
                   [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]],
        chartOptions: {
          grid:{
            show: false,
            xaxis: {
    lines: {
      show: false
    }
    },
     yaxis: {
    lines: {
      show: false
    }
  }
          },
          dataLabels: {
            enabled: false
            },
        backgroundColor: '#C28535',
          chart: {
            id: 'vuechart-example'
          },
         xaxis: {
            labels: {
            show: false
           },
            categories: [0,2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,38,40,42]
          },
          yaxis:{
            labels: {
            show: false
           }
          },
          plotOptions: {
            heatmap: {
                colorScale: {
                    ranges: [
                      {
                        from: 0,
                        to: 5,
                        color: '#00A100',
                        name: 'low',
                      },
                      {
                        from: 5,
                        to: 10,
                        color: '#f4e000',
                        name: 'medium',
                      },
                      {
                        from: 10,
                        to: 15,
                        color: '#FFA500',
                        name: 'medium-high'
                      },
                      {
                        from:15,
                        to: 45,
                        color: '#ff2a00',
                        name: 'high',
                      }
        ]
      }
    }
  }
        },
        series: [{
          name: '0',
          data:  [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]}, {    
          name: '2',
          data:  [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]}, {    
          name: '4',
          data:  [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]}, {    
          name: '6',
          data:  [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]}, {    
          name: '8',
          data:  [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]}, {    
          name: '10',
          data:  [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]}, {    
          name: '12',
          data:  [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]}, {    
          name: '14',
          data:  [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]}, {    
          name: '16',
          data:  [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]}, {    
          name: '18',
          data:  [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]}, {    
          name: '20',
          data:  [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]}]
      }
    },
    methods: {
      getData: function() {
        if (this.parte=="First Half") {
            for(var j = 0; j <= 1200;j++)
                this.teamdata[this.getPos(this.gamedata.pos[j].posY)][this.getPos(this.gamedata.pos[j].posX)]++;        
                }        
        else {
            for(var j = 1201; j <= 2400;j++) 
                this.teamdata[this.getPos(this.gamedata.pos[j].posY)][this.getPos(this.gamedata.pos[j].posX)]++;
        }

      },
        getPos: function(pos){
          if (0<=pos && pos<=2) return 0;
          else if (2<pos && pos<=4) return 1;
          else if (4<pos && pos<=6) return 2;
          else if (6<pos && pos<=8) return 3;
          else if (8<pos && pos<=10) return 4;
          else if (10<pos && pos<=12) return 5;
          else if (12<pos && pos<=14) return 6;
          else if (14<pos && pos<=16) return 7;
          else if (16 <pos && pos<=18) return 8;
          else if (18<pos && pos<=20) return 9;
          else if (20<pos && pos<=22) return 10;
          else if (22<pos && pos<=24) return 11;
          else if (24<pos && pos<=26) return 12;
          else if (26<pos && pos<=28) return 13;
          else if (28<pos && pos<=30) return 14;
          else if (30<pos && pos<=32) return 15;
          else if (32<pos && pos<=34) return 16;
          else if (34<pos && pos<=36) return 17;
          else if (36<pos && pos<=38) return 18;
          else if (38<pos && pos<=40) return 19;
          else if (40<pos && pos<=42) return 20;
          else return 21;
    },
    populate: function() {
      return [{
          name: '0',
          data:  this.teamdata[0]}, {    
          name: '2',
          data:  this.teamdata[1]}, {    
          name: '4',
          data:  this.teamdata[2]}, {    
          name: '6',
          data:  this.teamdata[3]}, {    
          name: '8',
          data:  this.teamdata[4]}, {    
          name: '10',
          data:  this.teamdata[5]}, {    
          name: '12',
          data:  this.teamdata[6]}, {    
          name: '14',
          data:  this.teamdata[7]}, {    
          name: '16',
          data:  this.teamdata[8]}, {    
          name: '18',
          data:  this.teamdata[9]}, {    
          name: '20',
          data:  this.teamdata[10]
          }];
  }
    },
      watch: { 
        gamedata(){ 
          this.getData();
          this.series = this.populate();
          } 
      } 
};
</script>


 