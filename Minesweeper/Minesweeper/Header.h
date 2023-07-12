#pragma once

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>
using namespace std;

#define max_mine 99
#define max_side 25
#define max_move 526

int SIDE;
int MINES;

void clear();
bool isValid(int row, int col);
bool isMine(int row, int col, char board[][max_side]);
void makeMove(int& x, int& y);
void alignedNumbers(int SIDE);
void printBoardRowByRow(char board[][max_side]);
void printBoard(char board[][max_side]);
void addCount(int& count, int row, int col, char realBoard[][max_side]);
int countAdjacentMines(int row, int col, int mines[][2], char realBoard[][max_side]);
void countMines(char myBoard[][max_side], char realBoard[][max_side], int mines[][2], int row, int col, int* movesLeft);
void continuePlaying(char myBoard[][max_side], char realBoard[][max_side], int mines[][2], int row, int col, int* movesLeft);
bool alreadyUncovered(char myBoard[][max_side], int row, int col);
int countUncoveredCells(char board[][max_side]);
bool playMinesUntil(char myBoard[][max_side], char realBoard[][max_side], int mines[][2], int row, int col, int* movesLeft);
void generateMines(int mines[][2], char realBoard[][max_side], bool mark);
void placeMines(int mines[][2], char realBoard[][max_side]);
void initialize(char realBoard[][max_side], char myBoard[][max_side]);

// Function to clear the console screen
void clear()
{
    // Clears the console screen and positions the cursor at the top - left corner, 
    // provides a way to create a clear screen before printing new content
    cout << "\033[2J\033[1;1H";
}

// Function to check if given cell coordinates are valid
bool isValid(int row, int col)
{
    return (row >= 0) && (row < SIDE) && (col >= 0) && (col < SIDE);
}

// Function to check if the given cell contains a mine
bool isMine(int row, int col, char board[][max_side])
{
    return (board[row][col] == '*');
}

// Function to get the user's move coordinates
void makeMove(int& x, int& y)
{
    cout << "\nEnter your move: [row] [column] -> ";
    cin >> x >> y;
}

// Function to ensure numbers are aligned properly
void alignedNumbers(int SIDE)
{
    // If the column number is greater than 9, print only the tens digit followed by a space
    for (int i = 0; i < SIDE; i++)
    {
        if (i > 9)
        {
            cout << i / 10 << " ";
        }
        else
        {
            // Otherwise, print two spaces to align the numbers properly
            cout << "  ";
        }
    }

}
// Function to print board row by row
void printBoardRowByRow(char board[][max_side])
{
    for (int i = 0; i < SIDE; i++)
    {
        cout << "\t\t\t    "; // Add indentation for better visualization

        // Print each cell of the current row followed by a space
        for (int j = 0; j < SIDE; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << " " << i; // Print the row number at the end of the row
        cout << "\n"; // Move to the next line for the next row
    }
}

// Function to print the game board
void printBoard(char board[][max_side])
{
    clear();

    // Print the column headers (numbers) at the top of the board
    cout << "\n\n\t\t\t    ";

    alignedNumbers(SIDE);

    // Print the column numbers (ones digit) at the top of the board
    cout << "\n\t\t\t    ";

    for (int i = 0; i < SIDE; i++)
    {
        // Print the ones digit of the column number followed by a space    
        cout << i % 10 << " ";
    }
    cout << "\n\n";

    // Print the game board row by row
    printBoardRowByRow(board);
}

// Function to increment the count if the given cell contains a mine
void addCount(int& count, int row, int col, char realBoard[][max_side])
{
    // Check if the cell is valid and contains a mine
    if (isValid(row, col) && isMine(row, col, realBoard))
    {
        count++;// Increment the count
    }
}

// Function to count the number of adjacent mines to a given cell
int countAdjacentMines(int row, int col, int mines[][2], char realBoard[][max_side])
{
    int count = 0;

    // Check the cell above
    addCount(count, row - 1, col, realBoard);
    // Check the cell below
    addCount(count, row + 1, col, realBoard);
    // Check the cell to the right
    addCount(count, row, col + 1, realBoard);
    // Check the cell to the left
    addCount(count, row, col - 1, realBoard);
    // Check the cell at the top left
    addCount(count, row - 1, col - 1, realBoard);
    // Check the cell at the top right
    addCount(count, row - 1, col + 1, realBoard);
    // Check the cell at the bottom left
    addCount(count, row + 1, col - 1, realBoard);
    // Check the cell at the bottom right
    addCount(count, row + 1, col + 1, realBoard);

    return count;
}

// If no adjacent mines, recursively play for adjacent cells
void countMines(char myBoard[][max_side], char realBoard[][max_side], int mines[][2], int row, int col, int* movesLeft)
{
    // Check the cell above
    if (isValid(row - 1, col) && (myBoard[row - 1][col] == '-'))
    {
        playMinesUntil(myBoard, realBoard, mines, row - 1, col, movesLeft);
    }
    // Check the cell below
    if (isValid(row + 1, col) && (myBoard[row + 1][col] == '-'))
    {
        playMinesUntil(myBoard, realBoard, mines, row + 1, col, movesLeft);
    }
    // Check the cell to the right
    if (isValid(row, col + 1) && (myBoard[row][col + 1] == '-'))
    {
        playMinesUntil(myBoard, realBoard, mines, row, col + 1, movesLeft);
    }
    // Check the cell to the left
    if (isValid(row, col - 1) && (myBoard[row][col - 1] == '-'))
    {
        playMinesUntil(myBoard, realBoard, mines, row, col - 1, movesLeft);
    }
    // Check the cell at the top left
    if (isValid(row - 1, col - 1) && (myBoard[row - 1][col - 1] == '-'))
    {
        playMinesUntil(myBoard, realBoard, mines, row - 1, col - 1, movesLeft);
    }
    // Check the cell at the top right
    if (isValid(row - 1, col + 1) && (myBoard[row - 1][col + 1] == '-'))
    {
        playMinesUntil(myBoard, realBoard, mines, row - 1, col + 1, movesLeft);
    }
    // Check the cell at the bottom left
    if (isValid(row + 1, col - 1) && (myBoard[row + 1][col - 1] == '-'))
    {
        playMinesUntil(myBoard, realBoard, mines, row + 1, col - 1, movesLeft);
    }
    // Check the cell at the bottom right
    if (isValid(row + 1, col + 1) && (myBoard[row + 1][col + 1] == '-'))
    {
        playMinesUntil(myBoard, realBoard, mines, row + 1, col + 1, movesLeft);
    }
}

// No mine encountered, continue playing
void continuePlaying(char myBoard[][max_side], char realBoard[][max_side], int mines[][2], int row, int col, int* movesLeft)
{
    // Count the number of adjacent mines to the current cell
    int count = countAdjacentMines(row, col, mines, realBoard);

    (*movesLeft)--; // Decrement the number of remaining moves
    myBoard[row][col] = count + '0'; // Update the player's board with the count of adjacent mines 

    // Allows the game to automatically uncover adjacent cells when a cell with no adjacent mines is selected
    if (!count)
    {
        countMines(myBoard, realBoard, mines, row, col, movesLeft);

    }
}

// Check if the current cell has already been uncovered
bool alreadyUncovered(char myBoard[][max_side], int row, int col)
{
    if (myBoard[row][col] != '-')
    {
        return false;
    }
}

// Function to count the number of uncovered cells on the board
int countUncoveredCells(char board[][max_side])
{
    int count = 0;
    for (int i = 0; i < SIDE; i++)
    {
        for (int j = 0; j < SIDE; j++)
        {
            if (board[i][j] != '-')
                // Increment the count if the cell is not covered (contains a digit or mine)
                count++;
        }
    }
    return count;
}

// Function to recursively play the game until a mine is encountered or the game is won
bool playMinesUntil(char myBoard[][max_side], char realBoard[][max_side], int mines[][2], int row, int col, int* movesLeft)
{
    alreadyUncovered(myBoard, row, col);

    // Check if the current cell contains a mine
    if (realBoard[row][col] == '*')
    {
        // Game over, mine encountered
        // Update the player's board to reveal the mine and all other mines        
        for (int i = 0; i < MINES; i++)
        {
            myBoard[mines[i][0]][mines[i][1]] = '*';
        }
        printBoard(myBoard);
        cout << "\nYou lost!\n";
        return true;
    }
    else
    {
        continuePlaying(myBoard, realBoard, mines, row, col, movesLeft);
    }

    // Update the number of remaining moves (*movesLeft)
    (*movesLeft) = SIDE * SIDE - countUncoveredCells(myBoard);

    // Checks if the number of uncovered cells is equal to the total number of cells on the game board minus the number of mines
    int uncoveredCells = SIDE * SIDE - *movesLeft;
    if (uncoveredCells == SIDE * SIDE - MINES)
    {
        // Game won, all non-mine cells uncovered
        printBoard(myBoard);
        cout << "\nYou won!\n";
        return true;
    }
    return false;
}
// Function to generate random place for the mines
void generateMines(int mines[][2], char realBoard[][max_side], bool mark[])
{
    for (int i = 0; i < MINES;)
    {
        // Generate a random number between 0 and the total number of cells on the game board
        int random = rand() % (SIDE * SIDE);
        int x = random / SIDE;
        int y = random % SIDE;

        // Check if the current random number has already been marked
        if (mark[random] == false)
        {
            // If the random number has not been marked, assign the mine coordinates
            mines[i][0] = x;
            mines[i][1] = y;

            // Place the mine on the real board
            realBoard[mines[i][0]][mines[i][1]] = '*';

            // Mark the random number as true in the mark array to indicate that it has been used
            mark[random] = true;
            i++;// Increment the mine counter
        }
    }
}

// Function to randomly place mines on the board
void placeMines(int mines[][2], char realBoard[][max_side])
{
    // Ensure that each mine is placed in a unique cell on the game board
    bool mark[max_side * max_side];

    // Initialize the mark array to false
    memset(mark, false, sizeof(mark));

    generateMines(mines, realBoard, mark);
}

// Function to initialize the game board
void initialize(char realBoard[][max_side], char myBoard[][max_side])
{
    srand(time(NULL)); // Seed the random number generator with the current time

    // Iterate over each cell of the game board
    for (int i = 0; i < SIDE; i++)
    {
        for (int j = 0; j < SIDE; j++)
        {
            // Set the initial value of the cells on both the player's board and the real board to '-'
            myBoard[i][j] = realBoard[i][j] = '-';
        }
    }
}

