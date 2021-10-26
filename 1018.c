#include <stdio.h>

int count_color(int board[8][8], char color)
{
    int i;
    int j;
    int ret;

    ret = 0;
    i = 0;
    j = 0;
    while (i < 8)
    {
        while (j < 8)
        {
            if (board[i][j] != color)
                ret++;
            if (color == 'W')
                color = 'B';
            else
                color = 'W';
            j++;
        }
        if (color == 'W')
            color = 'B';
        else
            color = 'W';
        j = 0;
        i++;
    }
    return (ret);
}

int fill_newboard(char ori[51][51], int r, int c)
{
    int i;
    int j;
    int temp;
    int ret[2];
    int new[8][8];

    temp = c;
    i = 0;
    j = 0;
    while (i < 8)
    {
        while (j < 8)
        {
            new[i][j] = (int)ori[r][c];
            c++;
            j++;
        }
        c = temp;
        j = 0;
        i++;
        r++;
    }
    ret[0] = count_color(new, 'B');
    ret[1] = count_color(new, 'W');
    if (ret[0] < ret[1])
        return(ret[0]);
    else
        return(ret[1]);
}

int main(void)
{
    int row;
    int col;
    int i;
    int j;
    int min;
    int temp;
    char board[51][51];

    i = 0;
    j = 0;
    min = 2147483647;
    scanf("%d %d", &row, &col);
    while (i < row)
        scanf("%s",board[i++]);
    i = 0;
    while (i <= row - 8)
    {
        while (j <= col - 8)
        {
            temp = fill_newboard(board, i, j);
            if (temp < min)
                min = temp;
            j++;
        }
        j = 0;
        i++;
    }
    printf("%d",min);
}