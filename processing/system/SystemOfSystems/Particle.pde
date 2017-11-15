class Particle {
 
  PVector acceleration;
  PVector position;
  PVector velocity;
  float lifespan;
  color c;
  
  Particle(PVector l) {
    position = l.get();
    velocity = new PVector(random(-1, 1), random(-2, 0));
    acceleration = new PVector(0, 0.05);
    lifespan = 255.0;
    c = color(random(0, 255), random(0, 255), random(0, 255));
  }
  
  void run() {
    update();
    display();
  }
  
  void update() {
    velocity.add(acceleration);
    position.add(velocity);
    lifespan -= 2.0;
  }
  
  void display() {
     fill(c, lifespan);
     noStroke();
     ellipse(position.x, position.y, 20, 20);
  }
  
  boolean isDead() {
     return lifespan < 0 ? true : false; 
  }
  
}