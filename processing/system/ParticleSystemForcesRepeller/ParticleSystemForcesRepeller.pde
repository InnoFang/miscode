ParticleSystem systems;
Repeller repeller1;
Repeller repeller2;
Repeller repeller3;
Repeller repeller4;

void setup() {
  size(1080, 780);
  smooth();
  systems = new ParticleSystem(new PVector(width / 2, 50));
  repeller1 = new Repeller(width / 2 - 120, 200);
  repeller2 = new Repeller(width / 2 - 40, 200);
  repeller3 = new Repeller(width / 2 + 40, 200);
  repeller4 = new Repeller(width / 2 + 120, 200);
}

void draw() {
  background(100);
  systems.addParticle();
  PVector gravity = new PVector(0, 0.1);
  systems.applyForce(gravity);
  
  systems.applyRepeller(repeller1);
  systems.applyRepeller(repeller2);
  systems.applyRepeller(repeller3);
  systems.applyRepeller(repeller4);
  
  systems.run();
  repeller1.display();
  repeller2.display();
  repeller3.display();
  repeller4.display();
}

/*
import java.util.*;

ArrayList<ParticleSystem> systems;
ArrayList<Repeller> repellers;

int count;
int sepr;

void setup() {
  size(1080, 780);
  smooth();
  systems = new ArrayList<ParticleSystem>();
  repellers = new ArrayList<Repeller>();
  
  sepr = 100;
  count = width / sepr;
  for (int i = 1; i <= sepr; i++) {
     systems.add(new ParticleSystem(new PVector(sepr * i, 50)));
     
  }
  
  for (int i = 1; i <= sepr; i++) {
     repellers.add(new Repeller(sepr * i, height - 200));
  }
  
}

void draw() {
  background(100);
  for(int i = 1; i < systems.size(); i++) {
     systems.get(i).addParticle(); 
     PVector gravity = new PVector(0, 0.1);
     systems.get(i).applyForce(gravity);
     systems.get(i).applyRepellers(repellers);
     
     systems.get(i).run();
  }
  
  for (int i = 0; i < repellers.size(); i++) {
     repellers.get(i).display();
  }
  
}
*/