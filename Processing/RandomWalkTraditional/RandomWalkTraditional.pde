class Walker {
    int x;
    int y;
    
    Walker() {
        x = width / 2;
        y = height / 2;
    }
    
    void display() {
        stroke(0);
        point(x, y);
    }
    
    void step() {
        /*int choice = int(random(4));
        if (choice == 0) {
           x++; 
        } else if(choice == 1) {
           x--; 
        } else if(choice == 2) {
           y++;
        } else if(choice == 3) {
           y--;  
        }*/
        
        /*int stepX = int(random(3)) - 1;
        int stepY = int(random(3)) - 1;
        
        x += stepX;
        y += stepY;
        */
        
        float stepx = random(-1,1);
        float stepy = random(-1,1);
        x += stepx;
        y += stepy;
    }
}

Walker w;

void setup() {
    size(1080, 1000);
    w = new Walker();
    background(255);
}

void draw() {
    w.step();
    w.display();
}