class GOL {
  
  int w = 8;
  int columns, rows;
  
  // Game of life board
  int[][] board;
  
  GOL() {
    columns = width / w;
    rows = height / w;
    board = new int[columns][rows];
    
    init();
  }
  
  void init() {
    
    for (int i = 1; i < columns - 1; i++) {
      for (int j = 1; j < rows - 1; j++) {
        board[i][j] = int(random(2)); 
      }
    }
   
    
    // 2017 lanqiao javab ac
    /*board[1][5] = 
    board[2][5] = 
    board[1][6] = 
    board[2][6] = 
    
    board[11][5] = 
    board[11][6] = 
    board[11][7] = 
    board[12][4] = 
    board[12][8] = 
    board[13][3] = 
    board[13][9] = 
    board[14][3] = 
    board[14][9] = 
    board[15][6] = 
    board[16][4] = 
    board[16][8] = 
    board[17][5] = 
    board[17][6] = 
    board[17][7] = 
    board[18][6] = 
    
    board[21][3] = 
    board[21][4] = 
    board[21][5] = 
    board[22][3] = 
    board[22][4] = 
    board[22][5] = 
    board[23][2] = 
    board[23][6] = 
    board[25][1] = 
    board[25][2] = 
    board[25][6] = 
    board[25][7] = 
    
    board[35][3] = 
    board[35][4] = 
    board[36][3] = 
    board[36][4] = 1; 
    */
  }
  
  void generate() {
    
    int[][] next = new int[columns][rows];
    
    // Loop through every spot in our 2D array and check spots neighbors
    for (int x = 1; x < columns - 1; x++) {
      for (int y = 1; y < rows - 1; y++) {
        
        // Add up all the states in a 3x3 surrounding grid 
        int neighbors = 0;
        for (int i = -1; i <= 1; i++) {
           for (int j = -1; j <= 1; j++) {
              neighbors += board[x + i][y + j];
           }
        }
        
        neighbors -= board[x][y];
        
        // Rules of Life
        if      ((board[x][y] == 1) && (neighbors <  2)) next[x][y] = 0;           // Loneliness
        else if ((board[x][y] == 1) && (neighbors >  3)) next[x][y] = 0;           // Overpopulation
        else if ((board[x][y] == 0) && (neighbors == 3)) next[x][y] = 1;           // Reproduction
        else                                             next[x][y] = board[x][y]; // Stasis
        
        /*
        if (neighbors <= 1 || neighbors >= 4) next[x][y] = 0;
        else if (neighbors == 3)              next[x][y] = 1;
        else                                  next[x][y] = board[x][y];
        */
      }
    }
    
    // Next is now our board
    board = next;
  }
  
  // This is the easy part, just draw the cells, fill 255 for '0', fill 0 for '1'
  void display() {
    for ( int i = 0; i < columns;i++) {
      for ( int j = 0; j < rows;j++) {
        if ((board[i][j] == 1)) fill(0);
        else                    fill(255); 
        stroke(0);
        rect(i*w, j*w, w, w);
      }
    }
  }
}