class Mover {
    
     PVector velocity;
     PVector acceleration;
     PVector position;
     
     // Mass is tied to size
     float mass;
     
     Mover(float m, float x, float y) {
         mass = m;
         position = new PVector(x, y);
         velocity = new PVector(0, 0);
         acceleration = new PVector(0, 0);
     }
     
     // Newton's 2nd law : F = M * A
     // or A = F / M
     void applyForce(PVector force) {
         // Divide by mass
         PVector a = PVector.div(force, mass);
         // Accumulate all forces in acceleration
         acceleration.add(a);
     }
     
     void update() {
         // Velocity changes according to acceleration
         velocity.add(acceleration);
         // position changed by velocity
         position.add(velocity);
         // We must clear acceleration each frame
         acceleration.mult(0);
     }
     
     // Draw Mover
     void display() {
         stroke(0);
         strokeWeight(2);
         fill(127, 200);
         ellipse(position.x, position.y, mass * 16, mass * 16);
     }
     
     // Bounce off bottom of window
     void checkEdge() {
         if (position.y > height) {
             velocity.y *= -1;
             position.y = height;
         }
     }
}