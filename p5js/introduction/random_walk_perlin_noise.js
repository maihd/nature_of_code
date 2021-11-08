const width = 640;
const height = 240;

const walker = { x: width * 0.5, y: height * 0.5, tx: 0, ty: 1000 };

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
    walker.x = map(noise(walker.tx), 0, 1, 0, width);
    walker.y = map(noise(walker.ty), 0, 1, 0, height);

    walker.tx += 0.01;
    walker.ty += 0.01;
}

function draw() {
    step();

    stroke(0);
    point(walker.x, walker.y);
}