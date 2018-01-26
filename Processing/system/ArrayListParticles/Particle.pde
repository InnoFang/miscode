class Particle {
  
  PVector acceleration;
  PVector velocity;
  PVector position;
  
  float lifespan;
  
  color bcolor;
  
  Particle(PVector l) {
    position = l.get();
    acceleration = new PVector(0, 0.05);
    velocity = new PVector(random(-3, 3), random(-3, 1));
    lifespan = 255.0;
    bcolor = color(random(0, 255), random(0, 255), random(0, 255));
  }
  
  void run() {
    update();
    display();
    checkEdge();
  }
  
  void update() {
    velocity.add(acceleration);
    position.add(velocity); 
    lifespan -= 0.8;
  }
  
  void display() {
    fill(bcolor, lifespan);
    noStroke();
    ellipse(position.x, position.y, 32, 32);
  }
  
  boolean isDead() {
    return lifespan < 0.0 ? true : false; 
  }
  
  void checkEdge() {
    if (position.x > width) {
      position.x = width;
      velocity.x *= -1;
    } else if (position.x < 0) {
      position.x = 0;
      velocity.x *= -1;
    }
    
    if (position.y > height) {
      position.y = height;
      velocity.y *= -1;
    } else if (position.y < 0) {
      position.y = 0;
      velocity.y *= -1;
    }
  }
}