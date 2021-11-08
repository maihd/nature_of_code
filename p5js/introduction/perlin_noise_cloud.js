const width = 200;
const height = 200;

function setup() {
    createCanvas(width, height);

    background(255);

    let tx = 0.0;
    for (let x = 0; x < width; x++) {
        let ty = 0.0;
        for (let y = 0; y < height; y++) {
            const bright = map(noise(tx, ty), 0, 1, 0, 255);
            
            noStroke();
            fill(bright);
            rect(x, y, 1, 1);

            ty += 0.01;
        }

        tx += 0.01;
    }
}