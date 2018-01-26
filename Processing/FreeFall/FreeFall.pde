float x = 100;
float y = 50;
float radius = 50;
float velocity = 0.0;
float acceleration = 0.3;
float friction = 0.999;
int k;
float[] array;
int count;
int jump;

void setup() {
    size(500, 700);
    frameRate(30);
    noStroke();
    ellipseMode(RADIUS);
    array = new float[2];
    k = 0;
    count = 0;
    jump = 0;
}

void draw() {
    count++;
    background(204);
    fill(255);
    ellipse(x, y, radius, radius);
    velocity += acceleration;
    velocity *= friction;
    y += velocity;
    
    if (y > (height - radius)) {
        y = height - radius;
        velocity = -velocity;
        jump++;
    }
    array[k] = y;
    if (array[0] == array[1]) {
       noLoop(); 
    }
    k++;
    k = k % 2;
    textSize(25);
    text("velocity = " + velocity, 200, 100);
    text("acceleration = " + acceleration, 200, 130);
    text("y = " + y, 200, 160);
    text("count = " + count, 200, 190);
    text("jump = " + jump, 200, 220);
}