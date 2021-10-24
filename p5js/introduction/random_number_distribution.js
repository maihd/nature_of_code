const width = 640;
const height = 240;

const randomCounts = Array(20);
for (let i = 0; i < randomCounts.length; i++) {
    randomCounts[i] = 0;
}

function setup() {
    createCanvas(width, height);
}

function draw() {
    background(255);

    const index = parseInt(random(randomCounts.length));
    randomCounts[index]++;

    stroke(0);
    fill(175);
    const w = width / randomCounts.length;
    for (let i = 0; i < randomCounts.length; i++) {
        const h = Math.min(randomCounts[i], height);

        rect(i * w, height - h, w, h);
    }
}