#include <iostream>
#include "TicTacToe.h"
using namespace std;

void displayBoard(char board[3][3]) {
    cout << "   |   |   " << endl;
    cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << "		(0-0) | (0-1) | (0-2) " << endl;
    cout << "___|___|___" << endl;
    cout << "   |   |   " << endl;
    cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << "		(1-0) | (1-1) | (1-2) " << endl;
    cout << "___|___|___" << endl;
    cout << "   |   |   " << endl;
    cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << "		(2-0) | (2-1) | (2-2) " << endl;
    cout << "   |   |   " << endl;
}

bool getPlayerMove(char board[3][3], char currentPlayer, int &row, int &col) {
    cout << "Current Player is " << currentPlayer << endl;
    while (true) {
        cout << "Enter r c from 0-2 for row and column: ";
        cin >> row >> col;
        if (row < 0 || row > 2 || col < 0 || col > 2) {
            cout << "Invalid input, try again." << endl;
        }
        else if (board[row][col] != ' ') {
            cout << "Tile is full, try again." << endl;
        }
        else {
            return true; // Valid move
        }
        // Clear input stream
        cin.clear(); 
        cin.ignore(10000, '\n'); 
    }
}

bool isBoardFull(char board[3][3]) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}

char checkWinner(char board[3][3]) {
    // Check rows
    for (int r = 0; r < 3; r++) {
        if (board[r][0] != ' ' && board[r][0] == board[r][1] && board[r][1] == board[r][2]) {
            return board[r][0];
        }
    }
    // Check columns
    for (int c = 0; c < 3; c++) {
        if (board[0][c] != ' ' && board[0][c] == board[1][c] && board[1][c] == board[2][c]) {
            return board[0][c];
        }
    }
    // Check diagonals
    if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return board[0][0];
    }
    else if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return board[0][2];
    }
    return ' '; // No winner yet
}

void printResult(char winner, const string& playerX, const string& playerO, char board[3][3]) {
    if (winner == 'X') {
        cout << "Congratulations " << playerX << ", you are the winner!" << endl;
    } else if (winner == 'O') {
	cout << "Congratulations " << playerO << ", you are the winner!" << endl; 
    } else {
	displayBoard(board);
	cout << "Tie!" << endl;
    }
}

