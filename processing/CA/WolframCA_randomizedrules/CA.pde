class CA {
  
  int[] cells;   // An array of 0s and 1s
  int generation; // How many generatinos?
  
  int[] ruleset;  // An array to store the ruleset, for example {0,1,1,0,1,1,0,1}
  
  int w = 5;
  
  CA(int[] r) {
    ruleset = r;
    cells = new int[width/w];
    restart();
  }
  
  // Make a random ruleset
  void randomize() {
    print("Current ruleset: [");
    for (int i = 0; i < ruleset.length; i++) {
       ruleset[i] = int(random(2)); 
       print(ruleset[i]);
       if (i != ruleset.length - 1) print(", ");
    }
    println("]");
    
  }
  
  // Reset to generation 0
  void restart() {
    for (int i = 0; i < cells.length; i++) {
      cells[i] = 0; 
    }
    // We arbitrarily start with just the middle cell having a state of "1"
    cells[cells.length/2] = 1;
    generation = 0;
  }
  
  void generate() {
    // First we create an empty array for the new values
    int[] nextgen = new int[cells.length];
    // For every spot, determine new state by examing current state, and neighbor states
    // Ignore edge that only have one neighbor
    for (int i = 1; i < cells.length - 1; i++) {
      int left = cells[i-1];
      int me   = cells[i];
      int right= cells[i+1];
      nextgen[i] = rules(left, me, right); // Compute next generation state based on ruleset
    }
    // The current generation is the new generation
    cells = nextgen;
    generation++;
  }
  
  void display() {
     for (int i = 0; i < cells.length; i++) {
        if (cells[i] == 1) fill(0);
        else               fill(255);
        noStroke();
        rect(i*w, generation*w, w, w);
    }
  }
  
  // Impelementing the Wolfram rules
  // This is the concise conversion to binary way
  int rules(int left, int me, int right) {
     String s = "" + left + me + right;
     int index = Integer.parseInt(s, 2);
     return ruleset[index];
  }
  
  // The CA is done if it reaches the bottom of the screen
  boolean finished() {
    return generation > height / w ? true : false;
  }
}