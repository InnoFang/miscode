class Mover {
  
  PVector acceleration;
  PVector velocity;
  PVector position;
  
  Mover() {
    acceleration = new PVector(0.01, 0,01);
    velocity = new PVector(0, 0);
    position = new PVector(random(width), random(height));
  }
  
  void update() {
    PVector mouse = new PVector(mouseX, mouseY);
    PVector dir = PVector.sub(mouse, position);
    
    dir.normalize();
    dir.mult(0.5);
    acceleration = dir;
    
    velocity.add(acceleration);
    velocity.limit(10);
    position.add(velocity);
  }
  
  void display() {
    stroke(0);
    strokeWeight(2);
    fill(127);
    ellipse(position.x, position.y, 32, 32);
  }
  
  void checkEdge() {
    if (position.x > width) {
      position.x = width;
      velocity.x *= - 1;
    } else if (position.x < 0) {
      position.x = 0;
      velocity.x *= -1;
    }
    
    if (position.y > height) {
      position.y = height;
      velocity.y *= -1;
    } else if(position.y < 0) {
      position.y = 0;
      velocity.y *= -1;
    }
  }
}