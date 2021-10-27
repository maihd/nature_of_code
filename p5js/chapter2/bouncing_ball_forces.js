class PVector {
    constructor(x = 0.0, y = 0.0) {
        this.x = x;
        this.y = y;
    }

    add(other) {
        this.x += other.x;
        this.y += other.y;
    }

    sub(other) {
        this.x -= other.x;
        this.y -= other.y;
    }

    mul(scalar) {
        this.x *= scalar;
        this.y *= scalar;
    }

    div(scalar) {
        this.x /= scalar;
        this.y /= scalar;
    }
}

class Mover {
    constructor() {
        this.location = new PVector(100, 100);
        this.velocity = new PVector(1, 3.3);
        this.acceleration = new PVector();
        this.mass = 1.0;
    }

    step(width, height) {
        this.location.add(this.velocity);
        this.velocity.add(this.acceleration);
        this.acceleration.mul(0);

        if ((this.location.x < 0) || (this.location.x > width)) {
            this.velocity.x = -this.velocity.x;
        }

        if ((this.location.y < 0) || (this.location.y > height)) {
            this.velocity.y = -this.velocity.y;
        }
    }

    applyForce(force) {
        const moreAccel = new PVector(force.x, force.y);
        moreAccel.div(this.mass);
        
        this.acceleration.add(moreAccel);
    }

    draw() {
        stroke(0);
        fill(175);
        ellipse(this.location.x, this.location.y, 16, 16);
    }
}

const width = 400;
const height = 200;

const mover = new Mover();

const wind = new PVector(0.01, 0.0);
const gravity = new PVector(0.0, 0.1);

function setup() {
    createCanvas(width, height);
}

function draw() {
    background(255);

    mover.applyForce(wind);
    mover.applyForce(gravity);

    mover.step(width, height);
    mover.draw();
}