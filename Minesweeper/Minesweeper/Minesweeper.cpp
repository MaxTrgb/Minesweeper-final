#include <iostream>
#include "Header.h"
using namespace std;

// Function to choose difficulty
void chooseDifficulty()
{
    clear();

    // Menu
    cout << "\t\t#     # ### #     # #######  #####  #     # ####### ####### ######  ####### ######" << endl;
    cout << "\t\t##   ##  #  ##    # #       #     # #  #  # #       #       #     # #       #     #" << endl;
    cout << "\t\t# # # #  #  # #   # #       #       #  #  # #       #       #     # #       #     #" << endl;
    cout << "\t\t#  #  #  #  #  #  # #####    #####  #  #  # #####   #####   ######  #####   ######" << endl;
    cout << "\t\t#     #  #  #   # # #             # #  #  # #       #       #       #       #   #" << endl;
    cout << "\t\t#     #  #  #    ## #       #     # #  #  # #       #       #       #       #    #" << endl;
    cout << "\t\t#     # ### #     # #######  #####   ## ##  ####### ####### #       ####### #     #" << endl;
    cout << "\n\t\t\t\t\t\tMINESWEEPER GAME";
    cout << "\n\n\t\t\tChoose difficulty level: ";
    cout << "\n\n\t\t\t1.Easy\n\t\t\t2.Medium\n\t\t\t3.Hard";
    cout << "\n\t\t\t4.Exit";
    cout << "\n\n\t\t\tEnter choice: ";

    // The user chooses the difficulty of the game
    int choice;
    cin >> choice;

    // Difficulty varies relative to the number of mines and the size of the field
    if (choice == 1) // Easy
    {
        SIDE = 9;
        MINES = 10;
    }
    else if (choice == 2) // Medium
    {
        SIDE = 16;
        MINES = 40;
    }
    else if (choice == 3) // Hard
    {
        SIDE = 24;
        MINES = 99;
    }
    else
        exit(4); // Exit   
}
// Function to play the Minesweeper game
void playMinesweeper()
{
    bool gameOver = false; // Variable to track if the game is over
    char realBoard[max_side][max_side];// Array to represent the real game board
    char myBoard[max_side][max_side]; // Array the player's board
    int movesLeft = SIDE * SIDE - MINES; // Variable to track the number of remaining moves
    int x, y; // Variables to store the user's move coordinates
    int mines[max_mine][2]; // Array to store the positions of the mines
    initialize(realBoard, myBoard); // Initialize the game board
    placeMines(mines, realBoard); // Place the mines randomly on the board

    int currentMoveIndex = 0; // Variable to track the current move index
    while (gameOver == false)
    {
        printBoard(myBoard); // Display the current state of the player's board

        makeMove(x, y); // Get the user's move coordinates

        currentMoveIndex++; // Increment the current move index
        gameOver = playMinesUntil(myBoard, realBoard, mines, x, y, &movesLeft); // Play the current move and check if the game is over
    }
}
int main()
{
    chooseDifficulty();
    playMinesweeper();
    return 0;
}
