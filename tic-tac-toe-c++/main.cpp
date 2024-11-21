#include <iostream>
#include <vector>

using namespace std;

const int SIZE = 3;
vector<vector<char>> board(SIZE, vector<char>(SIZE, ' '));
char currentPlayer = 'X';

void printBoard() {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            cout << board[i][j];
            if (j < SIZE - 1) cout << " | ";
        }
        cout << endl;
        if (i < SIZE - 1) cout << "--|---|--" << endl;
    }
}

bool checkWinner() {
    // Check rows and columns
    for (int i = 0; i < SIZE; ++i) {
        if (board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer) return true;
        if (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer) return true;
    }
    // Check diagonals
    if (board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer) return true;
    if (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer) return true;

    return false;
}

bool isDraw() {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            if (board[i][j] == ' ') return false;
        }
    }
    return true;
}

void handleMove(int row, int col) {
    if (board[row][col] == ' ') {
        board[row][col] = currentPlayer;
        if (checkWinner()) {
            printBoard();
            cout << "Player " << currentPlayer << " wins!" << endl;
            exit(0);
        } else if (isDraw()) {
            printBoard();
            cout << "It's a draw!" << endl;
            exit(0);
        } else {
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        }
    } else {
        cout << "Cell already occupied! Try again." << endl;
    }
}

int main() {
    int row, col;
    while (true) {
        printBoard();
        cout << "Player " << currentPlayer << ", enter your move (row and column): ";
        cin >> row >> col;
        if (row >= 0 && row < SIZE && col >= 0 && col < SIZE) {
            handleMove(row, col);
        } else {
            cout << "Invalid move! Try again." << endl;
        }
    }
    return 0;
}