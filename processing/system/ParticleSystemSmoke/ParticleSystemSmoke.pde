/* //smoke code 1
ParticleSystem ps;

void setup() {
  size(500, 500);
  ps = new ParticleSystem(new PVector(width / 2, height - 150));
}

void draw() {
  background(0);
  for (int i = 0; i < 2; i++) {
    ps.addParticle();
  }
  ps.run();
}
*/

ParticleSystem ps;

void setup() {
  size(400, 400);
  PImage img = loadImage("texture.png"); 
  ps = new ParticleSystem(0, new PVector(width / 2, height - 75), img);
}

void draw() {
  background(0);
  
  float dx = map(mouseX, 0, width, -0.2, 0.2);
  PVector wind = new PVector(dx, 0);
  ps.applyForce(wind);
  ps.run();
  for (int i = 0; i < 2; i++) {
    ps.addParticle();
  }
  
  // Draw an arrow representing the wind force
  drawVector(wind, new PVector(width / 2, 50, 0), 500);
}

void drawVector(PVector v, PVector pos, float scayl) {
  
  pushMatrix();
  float arrowsize = 4;
  
  // Translate to position to render vector
  translate(pos.x, pos.y);
  stroke(255);
  
  // Call vector heading function to get direction (note that pointing up is a heading of 0) and rotate
  rotate(v.heading2D());
  
  // Calculate length of vector & scale it to bigger or smaller if necessary
  float len = v.mag() * scayl;
  
  // Draw three lines to make an arrow (draw pointing up since we've rotate to proper direction)
  line(0, 0, len, 0);
  line(len, 0, len - arrowsize, +arrowsize / 2);
  line(len, 0, len - arrowsize, -arrowsize / 2);
  popMatrix();
}