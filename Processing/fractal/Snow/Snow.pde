import java.util.*;

SnowFlake sf;

void setup() {
  size(600, 692);
  sf = new SnowFlake(20, 20, 50);
}

void draw() {
  background(#33eeee);
  sf.run();
}