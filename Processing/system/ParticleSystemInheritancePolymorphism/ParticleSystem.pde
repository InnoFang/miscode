import java.util.*;

class ParticleSystem {
  
  ArrayList<Particle> particles;
  PVector origin;
  
  ParticleSystem(PVector position) {
    origin = position.get();
    particles = new ArrayList<Particle>();
  }
  
  ParticleSystem(int num, PVector position) {
    origin = position.get();
    particles = new ArrayList<Particle>();
    for (int i = 0; i < num; i++) {
      particles.add(new Particle(origin));
    }
  }
  
  void addParticle() {
    particles.add(random(1) < 0.5 ? new Particle(origin) : new Confetti(origin)); 
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