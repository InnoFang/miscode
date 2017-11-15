
GOL gol;

void setup() {
  size(640, 360);
  //size(304, 88);
  frameRate(24);
  gol = new GOL();
}

void draw() {
  background(255);

  gol.generate();
  gol.display();
}

// reset board when mouse is pressed
void mousePressed() {
  gol.init();
}