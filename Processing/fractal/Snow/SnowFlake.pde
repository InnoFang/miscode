import java.util.*;

class SnowFlake {
  
  PVector position;
  PVector acceleration;
  PVector velocity;
  
  ArrayList<KochLine> lines; // A list to keep track of all the lines
  
  SnowFlake(float topLeftX, float topLeftY, float snowWidth_) {
    
    position = new PVector(topLeftX, topLeftY);
    velocity = new PVector(0, random(1, 3));
    acceleration = new PVector(0, 0.05);
    
    lines = new ArrayList<KochLine>();
    PVector a = new PVector(topLeftX, topLeftY);
    PVector b = new PVector(topLeftX+snowWidth_, topLeftY);
    PVector c = new PVector(topLeftX+snowWidth_/2, topLeftY + snowWidth_*sin(radians(60)));
    
    // Starting with additional lines
    lines.add(new KochLine(a, b));
    lines.add(new KochLine(b, c));
    lines.add(new KochLine(c, a));
    
      for (int i = 0;  i < 5; i++) {
      generate(); 
    }
    
    smooth();
  }
  
  void run() {
    update();
    display();
  }
  
  void update() {
    velocity.add(acceleration);
    position.add(velocity);
  }
  
  void display() {
    pushMatrix();
    rotate(0.05);
    beginShape();
    for (KochLine l: lines) {
      l.display(); 
    }
    endShape();
    popMatrix();
  }
  
  void generate() {
    ArrayList<KochLine> next = new ArrayList<KochLine>();
    for (KochLine l: lines) {
      // Calculate 5 koch PVectors (done for us by the line object)
      PVector a = l.kochA();
      PVector b = l.kochB();
      PVector c = l.kochC();
      PVector d = l.kochD();
      PVector e = l.kochE();
      
      // Make line segments between all the PVectors and add them
      next.add(new KochLine(a, b));
      next.add(new KochLine(b, c));
      next.add(new KochLine(c, d));
      next.add(new KochLine(d, e));
    }
    lines = next;
  }
}