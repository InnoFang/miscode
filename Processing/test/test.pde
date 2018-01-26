/*
float angle = 0;

void setup() {
  size(640, 640);
  
  stroke(0);
  strokeWeight(2);
  fill(127);
  smooth();
}


void draw() {
  background(255);
  
  translate(width / 2, height / 2);
  angle += 0.01;
  rotate(angle);
  line(-50, 50, 50, -50);
  ellipse(50, -50, 32, 32);
  ellipse(-50, 50, 32, 32);
}
*/

/*
float r = 75;
float theta = 0;

void setup() {
  size(460, 460);
  
  smooth();
  strokeWeight(2);
  fill(127);
}

void draw() {
  background(255);
  translate(width / 2, height / 2);
  float x = r * cos(theta);
  float y = r * sin(theta);
  
  line(0, 0, x, y);
  ellipse(x, y, 32, 32);
  theta += 0.03;
}
*/


float angle = 0;
float aVelocity = 0.05;

void setup() {
  size(200, 200);
}

void draw() {
  background(255);
  
  float amplitude = 100;
  float x = amplitude * cos(angle);
  angle += aVelocity;
  
  ellipseMode(CENTER);
  stroke(2);
  fill(175);
  translate(width / 2, height / 2);
  line(0, 0, x, 0);
  ellipse(x, 0, 20, 20);
}