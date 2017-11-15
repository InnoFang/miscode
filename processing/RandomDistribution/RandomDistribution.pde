int[] randomCounts; // restore the select times of random number 

void setup() {
  size(640, 240);
  randomCounts = new int[20];
}

void draw() {
   background(255); // background color
   
   int index = int(random(randomCounts.length)); // select a random number, and count it
   randomCounts[index]++;
   
   stroke(0);
   fill(127);
   int w = width/randomCounts.length;
   
   for (int x = 0; x < randomCounts.length; x++){ // draw
        rect(x*w, height - randomCounts[x], w-1,randomCounts[x]); 
   }
   
}