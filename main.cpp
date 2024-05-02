#include <iostream>
#include "player.h"
#include "TicTacToe.h"
using namespace std;

int main() {
    char board[3][3] = {
        {' ', ' ', ' '}, 
        {' ', ' ', ' '}, 
        {' ', ' ', ' '}
    };

    string playerX;
    string playerO;
    char currentPlayerSymbol = 'X';
    char winner = ' ';

    // Get player names
    getPlayerNames(playerX, playerO);
    //Game
    while (winner == ' ' && !isBoardFull(board)) {
        displayBoard(board);
        
        int row, col;
        if (getPlayerMove(board, currentPlayerSymbol, row, col)) {
            board[row][col] = currentPlayerSymbol;
            winner = checkWinner(board);
	    currentPlayerSymbol = (currentPlayerSymbol == 'X') ? 'O' : 'X';
    	} else {
	    cout << "the tile you chose is already taken. Please select an open one" << endl;
	}
    }
    printResult(winner, playerX, playerO, board);
    
    return 0;
}
