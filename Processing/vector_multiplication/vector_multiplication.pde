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
    
    void mult(float n) {
        x = x * n;
        y = y * n;
    }
}

void setup() {
    size(800, 500);
    smooth();
}

void draw() {
    background(255);
    PVector mouse = new PVector(mouseX, mouseY);
    PVector center = new PVector(width/2, height/2);
    mouse.sub(center);
    mouse.mult(0.5);
    translate(width/2, height/2); // draw a line representation vector
    line(0, 0, mouse.x, mouse.y);
}