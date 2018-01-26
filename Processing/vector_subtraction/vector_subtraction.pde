class PVector {
    
    float x;
    float y;
    
    PVector(float x, float y) {
        this.x = x;
        this.y = y;
    }
    
    void add(PVector v) {
        y = y + v.y;
        x = x + v.x;
    }
    
    void sub(PVector v) {
        x = x - v.x;
        y = y - v.y;
    }
}

void setup() {
    size(500, 500); 
}
void draw() {
    background(255);
    PVector mouse = new PVector(mouseX, mouseY);
    PVector center = new PVector(width/2, height/2 );
    
    mouse.sub(center);
    
    translate(width/2, height/2);
    line(0, 0, mouse.x, mouse.y);
}