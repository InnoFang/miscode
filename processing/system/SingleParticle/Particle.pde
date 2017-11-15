class Particle {
  
  PVector acceleration;
  PVector velocity;
  PVector position;
  
  float lifespan;
  
  Particle(PVector l) {
    position = l.get();
    acceleration = new PVector(0, 0.05);
    velocity = new PVector(random(-1, 1), random(-1, 0));
    lifespan = 255.0;
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
    fill(127, lifespan);
    stroke(0, lifespan);
    strokeWeight(2);
    ellipse(position.x, position.y, 12, 12);
  }
  
  boolean isDead() {
    return lifespan < 0.0 ? true : false; 
  }
}