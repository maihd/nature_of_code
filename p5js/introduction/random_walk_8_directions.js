const width = 640;
const height = 240;

const walker = { x: width * 0.5, y: height * 0.5 };

function setup() {
    createCanvas(width, height);
    background(255);
}

function step() {
    walker.x += random(-1, 1);
    walker.y += random(-1, 1);
}

function draw() {
    step();

    stroke(0);
    point(walker.x, walker.y);
}