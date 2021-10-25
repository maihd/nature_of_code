const width = 400;
const height = 160;

function setup() {
    createCanvas(width, height);
}

let tx = 0;
let ty = 1000;

function draw() {
    background(255);

    const x = map(noise(tx), 0, 1, 0, width);
    const y = map(noise(ty), 0, 1, 0, height);

    stroke(0);
    fill(0, 0, 0, 255);
    ellipse(x, y, 16, 16);

    tx += 0.01;
    ty += 0.01;
}