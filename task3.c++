#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Function prototypes
void displayBoard(const vector<vector<char>>& board);
bool checkWin(const vector<vector<char>>& board, char player);
bool checkDraw(const vector<vector<char>>& board);
bool isValidMove(const vector<vector<char>>& board, int row, int col);
void updateBoard(vector<vector<char>>& board, int row, int col, char player);

int main() {
    vector<vector<char>> board(3, vector<char>(3, ' '));
    char currentPlayer = 'X';
    bool gameWon = false;
    bool gameDraw = false;

    cout << "Welcome to Tic-Tac-Toe!\n";

    do {
        displayBoard(board);

        int row, col;
        cout << "Player " << currentPlayer << ", enter your move (row column): ";
        cin >> row >> col;

        if (isValidMove(board, row, col)) {
            updateBoard(board, row, col, currentPlayer);
            gameWon = checkWin(board, currentPlayer);
            gameDraw = checkDraw(board);

            if (gameWon) {
                displayBoard(board);
                cout << "Player " << currentPlayer << " wins!\n";
            } else if (gameDraw) {
                displayBoard(board);
                cout << "It's a draw!\n";
            } else {
                // Switch players
                currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
            }
        } else {
            cout << "Invalid move! Please try again.\n";
        }

    } while (!gameWon && !gameDraw);

    cout << "Do you want to play again? (yes/no): ";
    string playAgain;
    cin >> playAgain;

    if (playAgain == "yes") {
        main(); // Restart the game
    } else {
        cout << "Thanks for playing!\n";
    }

    return 0;
}

void displayBoard(const vector<vector<char>>& board) {
    cout << "  0 1 2\n";
    for (int i = 0; i < 3; ++i) {
        cout << i << " ";
        for (int j = 0; j < 3; ++j) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

bool checkWin(const vector<vector<char>>& board, char player) {
    // Check rows, columns, and diagonals
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) return true; // Check rows
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) return true; // Check columns
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) return true; // Check diagonal 1
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) return true; // Check diagonal 2

    return false;
}

bool checkDraw(const vector<vector<char>>& board) {
    // Check if the board is full
    for (const auto& row : board) {
        for (char cell : row) {
            if (cell == ' ') return false;
        }
    }
    return true;
}

bool isValidMove(const vector<vector<char>>& board, int row, int col) {
    // Check if the cell is empty and within bounds
    return row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ';
}

void updateBoard(vector<vector<char>>& board, int row, int col, char player) {
    board[row][col] = player;
}