# Project-final

This code implements the Saper game in console mode. Let's consider the order of execution of functions:
1. chooseDifficulty(): This function displays the game difficulty selection menu and waits for user input. Depending on the selected difficulty, it sets the values of the SIDE and MINES variables, which determine the size of the field and the number of mines, respectively.
2. playMinesweeper(): This function is responsible for the Minesweeper game. It contains a basic gameplay loop that continues until the game is completed.
   
   In each iteration of the loop, the following is performed:
  
• printBoard(myBoard): Displays the current state of the playing field on the screen.

• makeMove(x, y): Asks the user to enter the coordinates of the move in the "row column" format.

• playMinesUntil(myBoard, realBoard, mines, x, y, &movesLeft): Makes a player's move, checks if the game is over, and updates myBoard depending on the outcome of the move.

4. main(): This function is the executive function of the program. It first calls chooseDifficulty() to select the difficulty, and then calls playMinesweeper() to start the game. After the game is over, the program returns.

    Other functions defined in header.h contain helper code to make the game work.
Here is an explanation of these features:

1. clear(): This function uses a special sequence of characters to clear the screen and move the cursor to the upper left corner of the console. It clears the screen before displaying new content.
   
3. isValid(int row, int col): This function checks whether the given row and col coordinates are valid for playing on the current field.
   
5. isMine(int row, int col, char board[][max_side]): This function checks whether a given cell on the field contains a mine.
   
7. makeMove(int& x, int& y): This function asks the user to enter a move (coordinates of the cell he wants to open) and stores them in x and y variables.
   
9. alignedNumbers(int SIDE): This function outputs the column numbers of the field, ensuring that the numbers are aligned using spaces.
    
11. printBoardRowByRow(char board[][max_side]): This function prints the board row by row, along with the row numbers.
    
13. printBoard(char board[][max_side]): This function outputs the game board to the screen, using printBoardRowByRow to output the board rows.
    
15. addCount(int& count, int row, int col, char realBoard[][max_side]): This function increments the count counter if the given cell on the field contains a mine.
    
17. countAdjacentMines(int row, int col, int mines[][2], char realBoard[][max_side]): This function counts the number of adjacent mines for a given cell.
    
19. countMines(char myBoard[][max_side], char realBoard[][max_side], int mines[][2], int row, int col, int* movesLeft): This function is called when the selected cell contains no mines and its neighboring cells also do not contain mines. It recursively opens all neighboring cells without mines.
    
21. continuePlaying(char myBoard[][max_side], char realBoard[][max_side], int mines[][2], int row, int col, int* movesLeft): This function is called when the selected cell contains no mines, but has nearby mines. It updates the playing field and the movesLeft counter.
    
23. alreadyUncovered(char myBoard[][max_side], int row, int col): This function checks whether the given cell is already uncovered on the playing field.
    
25. countUncoveredCells(char board[][max_side]): This function counts the number of uncovered cells on the playing field.
    
27. playMinesUntil(char myBoard[][max_side], char realBoard[][max_side], int mines[][2], int row, int col, int* movesLeft): This function executes the player's move, checks if the game is over (win or lose) and updates myBoard according to the outcome of the move.
    
29. generateMines(int mines[][2], char realBoard[][max_side], bool mark[]): This function generates random mine coordinates on the playing field. It uses the mark array to ensure the uniqueness of min.
    
31. placeMines(int mines[][2], char realBoard[][max_side]): This function places mines on the playing field using generateMines.
    
33. initialize(char realBoard[][max_side], char myBoard[][max_side]): This function initializes the fields realBoard and myBoard, filling them with the initial value "-". It also calls srand(time(NULL)) to initialize the random number generator.
