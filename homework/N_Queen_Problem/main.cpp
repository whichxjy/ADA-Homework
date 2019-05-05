#include <iostream>

// The number of queens
int N;
// The number of ways of placing these queens
int counter;

// A utility function to check if a queen can
// be placed on board[row][col]. Note that this
// function is called when "col" queens are
// already placed in columns from 0 to col -1.
// So we need to check only left side for
// attacking queens
bool isSafe(bool** board, int row, int col) {
    // Check this row on left side
    for (int i = 0; i < col; i++) {
        if (board[row][i]) {
            return false;
        }
    }

    // Check upper diagonal on left side
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j]) {
            return false;
        }
    }

    // Check lower diagonal on left side
    for (int i = row, j = col; j >= 0 && i < N; i++, j--) {
        if (board[i][j]) {
            return false;
        }
    }

    return true;
}

// A recursive utility function to solve N Queen problem
void solveNQUtil(bool** board, int col) {
    // Base case:
    // If all queens are placed, then return
    if (col >= N) {
        counter += 1;
        return;
    }

    // Consider this column and try placing 
    // this queen in all rows one by one
    for (int row = 0; row < N; row++) {
        // Check if the queen can be placed on board[i][col]
        if (isSafe(board, row, col)) {
            // Place this queen in board[row][col]
            board[row][col] = true;

            // recur to place rest of the queens
            solveNQUtil(board, col + 1);

            // BACKTRACK
            board[row][col] = false;
        }
    }
}

int main() {
    while (std::cin >> N) {
        counter = 0;
        bool** borad = new bool*[N];
        for (int i = 0; i < N; i++) {
            borad[i] = new bool[N];
        }
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                borad[i][j] = false;
            }
        }

        counter = 0;
        solveNQUtil(borad, 0);
        std::cout << counter << std::endl;

        for (int i = 0; i < N; i++) {
            delete[] borad[i];
        }
        delete[] borad;
    }
}
