PShape shape;

void setup() {
  size(100, 100);
  
  //shape = createShape(RECT, 0, 0, 80, 80);
  shape = loadShape("crazy-error.svg");
}

void draw() {
  shape(shape, 10, 10); 
}