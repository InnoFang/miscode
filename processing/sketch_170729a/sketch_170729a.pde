
size(200, 200);

float[] coswave = new float[width];

for (int i = 0; i < width; i++) {
  float amount = map(i, 0, width, 0, PI);
  coswave[i] = abs(cos(amount));
}

for (int i = 0; i < width; i++) {
  stroke(coswave[i]*255);
  line(i, 0, i, height/3);
}

for (int i = 0; i < width; i++) {
  stroke(coswave[i]*255 / 4);
  line(i, height/3, i, height/3*2);
}

for (int i = 0; i < width; i++) {
  stroke(255 - coswave[i]*255);
  line(i, height/3*2, i, height);
}