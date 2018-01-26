class Mover {
  
    // The Mover tracks position, velocity, and acceleration
    PVector position;
    PVector velocity;
    PVector acceleration;
    
    // The Mover's maximum speed
    float topspeed;
    
    Mover() {
        // Start in the center
        position = new PVector(random(width), random(height));
        velocity = new PVector(0, 0);
        topspeed = 5;
    }
    
    void update() {
      
         // Compute a vector that points from opsition to mouse
         PVector mouse = new PVector(mouseX, mouseY);
         acceleration = PVector.sub(mouse, position);
         
         // Set magnitude of acceleration
         // acceleration.setMat(0.2);
         acceleration.normalize();
         acceleration.mult(0.2);
         
         // Velocity changes according to acceleration
         velocity.add(acceleration);
         // Limit the velocity by topspeed
         velocity.limit(topspeed);
         // Position changes by velocity
         position.add(velocity);
    }
    
    void display() {
        stroke(0);
        strokeWeight(2);
        fill(127, 200);
        ellipse(position.x, position.y, 48, 48);
    }
}