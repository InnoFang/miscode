import java.util.*;

class ParticleSystem {
  
  ArrayList<Particle> particles;
  PVector origin;
  PImage img;
  
  ParticleSystem(int num, PVector v, PImage img_) {
    origin = v.get();
    particles = new ArrayList<Particle>();
    img = img_;
    for (int i = 0; i < num; i++) {
      particles.add(new Particle(origin, img)); 
    }
  }

  void applyForce(PVector dir) {
    for (Particle p: particles) {
      p.applyForce(dir); 
    }
  }

  void addParticle() {
    particles.add(new Particle(origin, img)); 
  }
 
  void run() {
    Iterator<Particle> it = particles.iterator();
    while(it.hasNext()) {
      Particle p = it.next();
      p.run();
      if (p.isDead()) {
        it.remove(); 
      }
    }
  }
}