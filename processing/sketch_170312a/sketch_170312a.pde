float x=0,y=0,x2=0,y2=0;
float easing = 0.01;
float Neasing = 0.05;
void setup() {
   size(1200, 700);
   stroke(10,50);
   background(253);
}
void draw(){
   x+=(mouseX-x)*easing;
   y+=(mouseY-y)*easing;
   x2+=(mouseX-x2)*Neasing;
   y2+=(mouseY-y2)*Neasing;
   line(x, y, x2, y2);
}