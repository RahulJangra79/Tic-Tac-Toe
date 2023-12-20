#include <stdio.h>

// Function to initialize the Tic Tac Toe board
void initializeBoard(char board[3][3]) 
{
    for (int i = 0; i < 3; i++) 
    {
        for (int j = 0; j < 3; j++) 
        {
            board[i][j] = ' ';
        }
    }
}

// Function to display the Tic Tac Toe board
void displayBoard(char board[3][3]) 
{
    for (int i = 0; i < 3; i++) 
    {
        //printf("%d ", i);
        for (int j = 0; j < 3; j++) 
        {
            printf("%c", board[i][j]);
            if (j < 2) 
            {
                printf("  |");
            }
        }
        printf("\n");
        if (i < 2) 
        {
            printf("---+---+---\n");
        }
    }
    printf("\n");
}

// Function to check if the game is over (win or draw)
int isGameOver(char board[3][3]) 
{
    // Check rows, columns, and diagonals for a win
    for (int i = 0; i < 3; i++) 
    {
        if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2]) 
        {
            return 1; // Someone won
        }
        if (board[0][i] != ' ' && board[0][i] == board[1][i] && board[1][i] == board[2][i]) 
        {
            return 1; // Someone won
        }
    }

    // Check diagonals
    if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) 
    {
        return 1; // Someone won
    }
    if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) 
    {
        return 1; // Someone won
    }

    // Check for a draw
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) 
        {
            if (board[i][j] == ' ') 
            {
                return 0; // The game is not over
            }
        }
    }

    return -1; // It's a draw
}

int main() 
{
    char board[3][3];
    int currentPlayer = 0; // 0 for player X, 1 for player O

    initializeBoard(board);

    printf("\n=================================");
    printf("\n>> WELCOME TO TIC TAC TOE GAME <<");
    printf("\n=================================\n");

    while (1) 
    {
        displayBoard(board);

        int row, col;
        printf("Player %c, enter your move (row and column): ", (currentPlayer == 0) ? 'X' : 'O');
        scanf("%d %d", &row, &col);

        if (row < 0 || row >= 3 || col < 0 || col >= 3 || board[row][col] != ' ') 
        {
            printf("Invalid move. Try again.\n");
            continue;
        }

        board[row][col] = (currentPlayer == 0) ? 'X' : 'O';

        int gameStatus = isGameOver(board);

        if (gameStatus == 1) 
        {
            displayBoard(board);
            printf("Player %c wins!\n", (currentPlayer == 0) ? 'X' : 'O');
            break;
        } else if (gameStatus == -1) 
        {
            displayBoard(board);
            printf("It's a draw!\n");
            break;
        }

        currentPlayer = 1 - currentPlayer; // Switch players
    }

    return 0;
}
