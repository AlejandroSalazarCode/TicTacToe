#ifndef TICTACTOE_H
#define TICTACTOE_H

#include <iostream>
#include <string>

using namespace std;

void displayBoard(char board[3][3]);
bool getPlayerMove(char board[3][3], char currentPlayer, int &row, int &col);
bool isBoardFull(char board[3][3]);
char checkWinner(char board[3][3]);
void printResult(char winner, const string& playerX, const string& playerO, char board[3][3]);

#endif
