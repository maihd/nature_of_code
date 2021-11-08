const walker = { x: 0.0, y: 0.0 };

function setup() {
    createCanvas(640, 240);
    background(255);

    walker.x = 320;
    walker.y = 120;
}

function step() {
    let choice = parseInt(random(5));
    switch (choice) {
        case 0:
            walker.x++;
            break;

        case 1:
            walker.x--;
            break;

        case 2:
            walker.y++;
            break;
        
        default:
            walker.y--;
            break;
    }
}

function draw() {
    step();

    stroke(0);
    point(walker.x, walker.y);
}