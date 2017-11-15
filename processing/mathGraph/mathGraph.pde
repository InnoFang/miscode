void setup() {
    size(1080, 760);
    noStroke();
    fill(0);
    float angle = 0.0;
    for (int x = 0; x <= width; x+= 5) {
        float y = 50 + (sin(angle) * 35.0);
        rect(x, y, 2, 4);
        angle += PI / 40.0;
    }
    fill(255);
    for (int x = 0; x <= width; x += 10) {
        float y = 50 + (cos(angle) * 35.0);
        rect(x, y, 2, 4);
        angle += PI / 40.0;
    }
    
    smooth();
    noFill();
    randomSeed(0);
    strokeWeight(10);
    stroke(0, 150);
    for (int i = 0; i < 1080; i += 10) {
       float begin = radians(i);
       float end = begin + HALF_PI;
       arc(500, 250, i, i, begin, end);
    }
    
    fill(255);
    noStroke();
    smooth();
    float radius = 1.0;
    for (int deg = 0; deg < 360 * 20; deg += 11) {
        float angle1 = radians(deg);
        float x = 500 + (cos(angle1) * radius);
        float y = 250 + (sin(angle1) * radius);
        ellipse(x, y, 6, 6);
        radius = radius + 0.34;
    }
}