
Mover[] movers = new Mover[20];

void setup() {
     size(640, 320);
     for (int i = 0; i < movers.length; i++) {
          movers[i] = new Mover(random(0.1, 4), 0, 0);
     }
}
int i = 0;
void draw() {
     background(255);
 
     PVector wind = new PVector(0.01, 0);
     PVector gravity = new PVector(0, 0.1);
     
     for (int i = 0; i < movers.length; i++) {
       
          float c = 0.01;
          PVector friction = movers[i].velocity.get();
          friction.normalize();
          friction.mult(-1);
          friction.mult(c);
       
          movers[i].applyForce(friction);
          movers[i].applyForce(wind);
          movers[i].applyForce(gravity);
          
          movers[i].update();
          movers[i].display();
          movers[i].checkEdges();
     }
}