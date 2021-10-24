const width = 640;
const height = 240;

function setup() {
    createCanvas(width, height);
    background(255);
}

function draw() {
    const x = randomGaussian(320, 60);

    noStroke();
    fill(0, 10);
    ellipse(x, height * 0.5, 16, 16);
}