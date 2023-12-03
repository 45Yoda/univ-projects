
function setup() {
  createCanvas(400, 600);

}


function draw() {

}

function draw_background(){
    var canvas = document.getElementById('defaultCanvas0');
    var context = canvas.getContext('2d');
    var back_image = new Image();
    back_image.src = 'backflappy.png';
    context.drawImage(back_image,0,0,400,600);
}
