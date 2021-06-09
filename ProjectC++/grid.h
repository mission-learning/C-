#ifndef PROJECT_GRID_H
#define PROJECT_GRID_H

#endif //PROJECT_GRID_H

#include <SFML/Graphics.hpp>
#include <time.h>
using namespace sf;


class Grid
{
    int **board;
    constexpr static size_t size = 15;

public:
    static constexpr size_t getSize()
    {
        return size;
    }

    int get(size_t x, size_t y) const
    {
        return board[x][y];
    }

    int ** getBoard() const
    {
        return board;
    }

    int* operator[](size_t i) const
    {
        return board[i];
    }

    Grid();
    void clearBoard();
    void setRow(int x,int yStart,int yEnd,int num);
    void checkRow(int num, Grid grid);
    void checkColumn(int num, Grid grid);
};
