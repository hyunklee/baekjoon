#include <stdio.h>
#include <stdlib.h>
int ret;

int check_space(char row, int col, char **board, int N)
{
    int dig_r;
    int dig_c;
    for (int i = 0; i < N; i++)
    {
        if(board[i][col] || board[row][i])
            return (0);
    }
    dig_r = row;
    dig_c = col;
    while (dig_r && dig_c)
    {
        dig_r--;
        dig_c--;
    }
    while (dig_r < N && dig_c < N)
    {
        if(board[dig_r][dig_c])
            return (0);
        dig_r++;
        dig_c++;
    }
    dig_r = row;
    dig_c = col;
    while (dig_r && dig_c + 1 < N)
    {
        dig_r--;
        dig_c++;
    }
    while (dig_r < N && dig_c)
    {
        if(board[dig_r][dig_c])
            return(0);
        dig_r++;
        dig_c--;
    }
    return (1);
}

void recursive(int N, char **board, char depth)
{
    if (depth == N)
    {
        ret++;
        return ;
    }
    for (int i = 0; i < N; i++)
    {
        if (check_space(depth, i, board, N))
        {
            board[depth][i] = 1;
            recursive(N, board, depth + 1);
            board[depth][i] = 0;
        }
    }
}

int main(void)
{
    int N;
    char **board;

    ret = 0;
    scanf("%d", &N);
    board = malloc(sizeof(char *) * N);
    for (int i = 0; i < N; i++)
        board[i] = calloc(N, sizeof(char));
    recursive(N, board, 0);
    printf("%d\n", ret);
}