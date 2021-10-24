const walker = { x: 0.0, y: 0.0 };

function setup() {
    createCanvas(640, 240);
    background(255);

    walker.x = 320;
    walker.y = 120;
}

let preferChoice = 0;
let preferChoiceCountDown = 0;

function step() {
    let choice = 0;
    
    const chance = random(100);
    if (chance <= 80) {
        choice = parseInt(chance / 20);
    } else {
        choice = preferChoice;

        preferChoiceCountDown--;
        if (preferChoiceCountDown <= 0) {
            preferChoiceCountDown = 10;

            do {
                preferChoice = parseInt(random(4));
            } while (preferChoice === choice);
        }
    }

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