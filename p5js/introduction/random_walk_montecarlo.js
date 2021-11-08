const width = 640;
const height = 240;

const walker = { x: width * 0.5, y: height * 0.5 };

function setup() {
    createCanvas(width, height);
    background(255);
}

function montecarlo() {
    while (true) {
        const r1 = random(1);
        const r2 = random(1);
        if (r2 < r1) {
            return r1;
        }
    }
}

function step() {
    const stepSize = montecarlo() * 10;

    walker.x += random(-stepSize, stepSize);
    walker.y += random(-stepSize, stepSize);
}

function draw() {
    step();

    stroke(0);
    point(walker.x, walker.y);
}