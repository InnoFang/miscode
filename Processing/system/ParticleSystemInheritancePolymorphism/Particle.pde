class Particle {
 
  PVector acceleration;
  PVector position;
  PVector velocity;
  float lifespan;
  color c;
  int r ;
  
  Particle(PVector l) {
    position = l.get();
    velocity = new PVector(random(-2, 2), random(-2, 0));
    acceleration = new PVector(0, 0.05);
    lifespan = 255.0;
    c = color(random(0, 255), random(0, 255), random(0, 255));
    r = (int)random(1, 30);
  }
  
  void run() {
    update();
    display(); 
    checkEdge();
  }
  
  void update() {
    velocity.add(acceleration);
    position.add(velocity);
    lifespan -= 1.0;
  }
  
  void display() {
     fill(c, lifespan);
     noStroke();
     ellipse(position.x, position.y, 20, 20);
  }
  
  boolean isDead() {
     return lifespan < 0 ? true : false; 
  }
  
  void checkEdge() {
    if(position.x > width) {
      position.x = width;
      velocity.x *= -1;
    } else if(position.x < 0) {
      position.x = 0;
      velocity.x *= -1;
    }
    
    if(position.y > height) {
      position.y = height;
      velocity.y *= -1;
    } else if(position.y < 0) {
      position.y = 0;
      velocity.y *= -1;
    }
  }
}