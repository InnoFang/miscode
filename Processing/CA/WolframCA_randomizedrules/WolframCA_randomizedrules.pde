CA ca;

int delay = 0;

void setup() {
  size(1080, 540);
  background(255);
  int[] ruleset = {
     0, 1, 0, 1, 1, 0, 1, 0
  }; // An initlial rule system
  ca = new CA(ruleset); // Initial CA
  frameRate(30);
}

void draw() {
  ca.display(); // Draw the CA
  ca.generate();
  
  if (ca.finished()) {
    delay++;
    if (delay > 30) {
       background(255);
       ca.randomize();
       ca.restart();
       delay = 0;
    }
  }
}

void mousePressed() {
  background(255);
  ca.randomize();
  ca.restart();
}