#include <stdio.h>
#include <stdbool.h>

#define N 8

bool isSafe(int row, int col, int slashCode[N][N], int backslashCode[N][N], bool rowLookup[], bool slashCodeLookup[], bool backslashCodeLookup[]) {
    if (slashCodeLookup[slashCode[row][col]] || backslashCodeLookup[backslashCode[row][col]] || rowLookup[row])
        return false;

    return true;
}

void printSolution(int board[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            printf("%d ", board[i][j]);
        printf("\n");
    }
    printf("\n");
}

bool solveNQUtil(int col, int slashCode[N][N], int backslashCode[N][N], bool rowLookup[], bool slashCodeLookup[], bool backslashCodeLookup[], int board[N][N]) {
    if (col >= N) {
        printSolution(board);
        return true;
    }

    bool res = false;
    for (int i = 0; i < N; i++) {
        if (isSafe(i, col, slashCode, backslashCode, rowLookup, slashCodeLookup, backslashCodeLookup)) {
            board[i][col] = 1;
            rowLookup[i] = true;
            slashCodeLookup[slashCode[i][col]] = true;
            backslashCodeLookup[backslashCode[i][col]] = true;

            res = solveNQUtil(col + 1, slashCode, backslashCode, rowLookup, slashCodeLookup, backslashCodeLookup, board) || res;

            board[i][col] = 0;
            rowLookup[i] = false;
            slashCodeLookup[slashCode[i][col]] = false;
            backslashCodeLookup[backslashCode[i][col]] = false;
        }
    }

    return res;
}

int main() {
    int board[N][N] = { {0} };
    int slashCode[N][N], backslashCode[N][N];

    bool rowLookup[N] = {false};
    bool slashCodeLookup[2*N - 1] = {false};
    bool backslashCodeLookup[2*N - 1] = {false};

    for (int r = 0; r < N; r++) {
        for (int c = 0; c < N; c++) {
            slashCode[r][c] = r + c;
            backslashCode[r][c] = r - c + 7;
        }
    }

    int startingRow, startingCol;

    printf("Enter the starting position for the first queen (row and column, 0-indexed, separated by space): ");
    scanf("%d %d", &startingRow, &startingCol);

    if (startingRow < 0 || startingRow >= N || startingCol < 0 || startingCol >= N) {
        printf("Invalid starting position! Please enter valid coordinates within the board.\n");
        return 1;
    }

    board[startingRow][startingCol] = 1;
    rowLookup[startingRow] = true;
    slashCodeLookup[slashCode[startingRow][startingCol]] = true;
    backslashCodeLookup[backslashCode[startingRow][startingCol]] = true;

    if (!solveNQUtil(startingCol + 1, slashCode, backslashCode, rowLookup, slashCodeLookup, backslashCodeLookup, board)) {
        printf("Solution does not exist.\n");
        return 1;
    }

    return 0;
}