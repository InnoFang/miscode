import java.util.*;

ArrayList<Particle> particles;

void setup() {
  size(1260, 860);
  particles = new ArrayList<Particle>();
}

void draw() {
  background(255);
  
  particles.add(new Particle(new PVector(mouseX, mouseY)));
  particles.add(new Particle(new PVector(mouseX, mouseY)));
  particles.add(new Particle(new PVector(mouseX, mouseY)));
  
  // Looping throungh backwards to delete
  Iterator<Particle> it = particles.iterator();
  while(it.hasNext()) {
    Particle p = it.next();
    p.run();
    if (p.isDead()) {
      it.remove(); 
    }
  }
}