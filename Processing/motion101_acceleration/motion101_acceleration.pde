class PVector {
    
    float x;
    float y;
    
    PVector(float x, float y) {
        this.x = x;
        this.y = y;
    }
    
    void add(PVector v) {
        y = y + v.y;
        x = x + v.x;
    }
    
    void sub(PVector v) {
        x = x - v.x;
        y = y - v.y;
    }
    
    void mult(float n) {
        x = x * n;
        y = y * n;
    }
    
    void limit(float max) {
       if(max > 10) {
           mult(max);
       }
    }
}
class Mover{
    PVector location;
    PVector velocity;
    
    PVector acceleration;
    float topspeed;
    
    Mover() {
        location = new PVector(width/2, height/2);
        velocity = new PVector(0, 0);
        acceleration = new PVector(-0.001, 0.01);
        topspeed = 10;
    }
    
    void update() {
       velocity.add(acceleration);
       velocity.limit(topspeed);
       location.add(velocity);
    }
    
    void display() {
       stroke(0);
       fill(175);
       ellipse(location.x, location.y, 16, 16);
    }
    
    void checkEdge() {
       if (location.x > width) {
         location.x = 0;
       } else if(location.x < 0) {
         location.x = width; 
       }
       if(location.y > height) {
         location.y = 0;
       } else if(location.y < 0) {
         location.y = width; 
       } 
    }
}

void setup() {
   size(800, 500);
}

Mover m = new Mover();
void draw() {
    m.display();
    m.checkEdge();
    m.update();
}