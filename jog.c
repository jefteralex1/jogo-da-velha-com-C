#include <stdio.h>

// Função para imprimir o tabuleiro
void print_board(char board[3][3]) {
    printf("\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf(" %c ", board[i][j]);
            if (j < 2) {
                printf("|");
            }
        }
        printf("\n");
        if (i < 2) {
            printf("---+---+---\n");
        }
    }
    printf("\n");
}

// Função para verificar se um jogador venceu
int check_win(char board[3][3], char player) {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return 1;
        }
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
            return 1;
        }
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return 1;
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return 1;
    }
    return 0;
}

// Função principal
int main() {
    char board[3][3] = {
        {'1', '2', '3'},
        {'4', '5', '6'},
        {'7', '8', '9'}
    };
    int num_plays = 0;
    int max_plays = 9;
    char player = 'X';
    int row, col;
    int winner = 0;
    while (num_plays < max_plays && !winner) {
        print_board(board);
        printf("Jogador %c, digite a linha e a coluna da jogada (ex: 1 2): ", player);
        scanf("%d %d", &row, &col);
        if (row < 1 || row > 3 || col < 1 || col > 3) {
            printf("Jogada inválida. Digite valores entre 1 e 3.\n");
            continue;
        }
        if (board[row-1][col-1] != 'X' && board[row-1][col-1] != 'O') {
            board[row-1][col-1] = player;
            num_plays++;
            if (check_win(board, player)) {
                winner = 1;
            }
            player = (player == 'X') ? 'O' : 'X';
        } else {
            printf("Jogada inválida. A posição (%d, %d) já foi jogada.\n", row, col);
        }
    }
    print_board(board);
    if (winner) {
        printf("Jogador %c venceu!\n", player);
    } else {
        printf("Empate!\n");
    }
    return 0;
}
