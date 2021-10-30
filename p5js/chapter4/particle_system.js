class PVector {
    constructor(x = 0, y = 0) {
        this.x = x;
        this.y = y;
    }

    get() {
        return new PVector(this.x, this.y);
    }

    add(other) {
        this.x += other.x;
        this.y += other.y;

        return this;
    }

    sub(other) {
        this.x -= other.x;
        this.y -= other.y;

        return this;
    }
}

class Particle {
    constructor(location) {
        this.location = location.get();
        this.velocity = new PVector(random(-1, 1), random(-2, 0));
        this.acceleration = new PVector(0, 0.05);
        this.lifespan = 255;
    }

    step() {
        this.update();
        this.display();
    }

    update() {
        this.velocity.add(this.acceleration);
        this.location.add(this.velocity);
        this.lifespan -= 2.0;
    }

    display() {
        stroke(0, this.lifespan);
        fill(175, this.lifespan);
        ellipse(this.location.x, this.location.y, 8, 8);
    }

    isDead() {
        return (this.lifespan < 0.0);
    }
}

const width = 400;
const height = 400;

let particle;

function setup() {
    createCanvas(400, 400);
    particle = new Particle(new PVector(width * 0.5, 10));
}

function draw() {
    background(255);

    particle.step();
    if (particle.isDead()) {
        particle = new Particle(new PVector(width * 0.5, 10));
    }
}