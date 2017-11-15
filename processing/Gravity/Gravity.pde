
Mover mover;

void setup() {
  mover = new Mover();
  
  size(1280, 960);
  stroke(0);
  strokeWeight(2);
  fill(127);
}

void draw() {
  background(255);
  mover.update();
  mover.display();
  mover.checkEdge();
}