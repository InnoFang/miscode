float theta;

void setup() {
  size(800, 400);
  smooth();
}

void draw(){
  background(255);
  
  theta = map(mouseX, 0, width, 0, PI/2);
  translate(width/2, height);
  stroke(0);
  branch(100, 10);
}

void branch(float len, float strokeWei) {
  strokeWeight(strokeWei);
  
  line(0, 0, 0, -len);
  translate(0, -len);
  
  len *= 0.66;
  
  if(len > 2) {
    pushMatrix();
    rotate(theta);
    branch(len, strokeWei * 0.7);
    popMatrix();
    
    pushMatrix();
    rotate(-theta);
    branch(len, strokeWei * 0.7);
    popMatrix();
  }
}