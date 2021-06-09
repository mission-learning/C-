
#include "grid.h"

Grid::Grid() {

    board = new int*[size];
    for(int i = 0; i < (int)size; i++)
    {
        board[i] = new int[size];
    }

    for(int i = 0 ; i < 15;i++)
    {
        for(int j = 0 ; j < 15; j++)
        {
            board[i][j] = 0;
        }
    }
}

void Grid::clearBoard()
{
    for(int i = 0 ; i < 15;i++)
    {
        for(int j = 0 ; j < 15; j++)
        {
            board[i][j] = 0;
        }
    }
}

void Grid::setRow(int x,int yStart,int yEnd,int num)
{
    for(int i = yStart; i <= yEnd;i++)
    {
        board[x][i] = num;
    }
}
void Grid::checkRow(int num, Grid grid)
{
    for(int i = 0; i < (int)size; i++)
    {
        if(grid[num][i] > 2)
        {
            if (grid[num][i] != board[num][i])
            {
                return;
            }
        }
    }

    for(int i = 0; i < (int)size; i++)
    {
        if(board[num][i] == 0)
        {
            board[num][i] = 2;
        }
    }
}

void Grid::checkColumn(int num, Grid grid)
{
    for(int i = 0; i < (int)size; i++)
    {
        if(grid[i][num] > 2)
        {
            if (grid[i][num] != board[i][num])
            {
                return;
            }
        }
    }

    for(int i = 0; i < (int)size; i++)
    {
        if(board[i][num] == 0)
        {
            board[i][num] = 2;
        }
    }
}