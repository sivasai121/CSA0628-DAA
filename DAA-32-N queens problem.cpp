#include <stdio.h>
#include <stdbool.h>

void printSolution(int board[][100], int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

bool isSafe(int board[][100], int row, int col, int N) {
    int i, j;
    // Check for queens in the same column
    for (i = 0; i < row; i++)
        if (board[i][col])
            return false;

    // Check upper diagonal on left side
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;

    // Check upper diagonal on right side
    for (i = row, j = col; i >= 0 && j < N; i--, j++)
        if (board[i][j])
            return false;

    return true;
}

bool solveNQueensUtil(int board[][100], int row, int N) {
    if (row >= N)
        return true;

    for (int col = 0; col < N; col++) {
        if (isSafe(board, row, col, N)) {
            board[row][col] = 1;

            if (solveNQueensUtil(board, row + 1, N))
                return true;

            board[row][col] = 0; // backtrack
        }
    }

    return false;
}

bool solveNQueens(int N) {
    int board[100][100] = {0};

    if (solveNQueensUtil(board, 0, N) == false) {
        printf("Solution does not exist");
        return false;
    }

    printSolution(board, N);
    return true;
}

int main() {
    int N;
    printf("Enter the value of N: ");
    scanf("%d", &N);
    solveNQueens(N);
    return 0;
}
