
Particle p;

void setup() {
  size(640, 360);
  p = new Particle(new PVector(width / 2, 20));
  background(255);
  smooth();
}

void draw() {
  p.run();
  if (p.isDead()) {
    p = new Particle(new PVector(width / 2, 20)); 
  }
}