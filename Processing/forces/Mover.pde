class Mover {

    PVector position;
    PVector velocity;
    PVector acceleration;
    
    float mass;
    
    Mover() {
        position = new PVector(30, 30);
        velocity = new PVector(0, 0);
        acceleration = new PVector(0, 0);
        mass = 1;
    }
    
    void applyForce(PVector force) {
         PVector a = PVector.div(force, mass);
         acceleration.add(a);
    }
    
    void update() {
         velocity.add(acceleration);
         position.add(velocity);
         acceleration.mult(0);
        
    }
    
    void display() {
        stroke(0);
        strokeWeight(2);
        fill(127);
        ellipse(position.x, position.y, 48, 48);
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