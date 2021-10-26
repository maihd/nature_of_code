const width = 400;
const height = 400;

const position = { x: 100, y: 100 };
const velocity = { x: 1, y: 3.3 };

function setup() {
    createCanvas(400, 400);
}

function draw() {
    background(255);

    position.x += velocity.x;
    position.y += velocity.y;

    if ((position.x > width) || (position.x < 0)) {
        velocity.x = -velocity.x;
    }
    
    if ((position.y > height) || (position.y < 0)) {
        velocity.y = -velocity.y;
    }

    stroke(0);
    fill(175);
    ellipse(position.x, position.y, 16, 16);
}