//desenha pipe superior
/*
function draw_Pipe_top(x,y,z){
    var canvas = document.getElementById('defaultCanvas0');
    var context = canvas.getContext('2d');
    var pipe_main = new Image();
    var pipe_mainAux = new Image();
    z = z - 22;
    pipe_main.src = 'pipe_main.png';
    pipe_mainAux.src = 'pipe_aux.png';
    context.drawImage(pipe_main,x+3,y,30,z);
    context.drawImage(pipe_mainAux,x,z-3,36,22);
}

function draw_Pipe_bottom(x,y,z){
  var canvas = document.getElementById('defaultCanvas0');
  var context = canvas.getContext('2d');
  var pipe_main = new Image();
  var pipe_mainAux = new Image();
  pipe_main.src = 'pipe_main.png';
  pipe_mainAux.src = 'pipe_aux.png';
  context.drawImage(pipe_main,x+3,y+22,30,z-22); //(img,x,y,width,height)
  context.drawImage(pipe_mainAux,x,y,36,22);
}
*/
