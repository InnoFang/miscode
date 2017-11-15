class Repeller {
  float strength = 100;
  PVector location;
  float r = 10;
  
  Repeller(float x, float y) {
    location = new PVector(x, y); 
  }
  
  void display() {
    stroke(255);
    fill(255);
    ellipse(location.x, location.y, r * 6, r * 6);
  }
  
  PVector repel(Particle p) {
    PVector dir = PVector.sub(location, p.position);
    float d = dir.mag();
    dir.normalize();
    d = constrain(d, 5, 100);
    float force = -1 * strength / (d * d);
    dir.mult(force);
    return dir;
  }
 
}