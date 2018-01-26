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
    particles.add(new Particle(origin)); 
  }
  
  void applyForce(PVector f) {
     for (Particle p: particles) {
        p.applyForce(f);
     }
  }
  
  void applyRepeller(Repeller r) {
    for (Particle p: particles) {
      PVector force = r.repel(p);
      p.applyForce(force);
    }
  }
  
    void applyRepellers(ArrayList<Repeller> rs) {
    for (Particle p: particles) {
      for (int i = 0; i < rs.size(); i++) {
         PVector force = rs.get(i).repel(p);
         p.applyForce(force);
      }
    }
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