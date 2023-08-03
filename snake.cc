#include <iostream>
#include <ncurses.h>
#include <cstdlib>
#include <stdlib.h>

using namespace std;

int getStartPointRowCoordination();
int getStartPointColCoordination();
char getDirection();
void printDirection(char direction, char *lastDirection, int *row, int *col, int *randomRow, int *randomCol, int rowMax, int colMax);
void printUp(int *row, int *col);
void printDown(int *row, int *col);
void printRight(int *row, int *col);
void printLeft(int *row, int *col);
void makeRandomStarCoordination(int *row, int *col, int rowMax, int colMax);
void drawGameBorder(int rowMax, int colMax);
void upOfBorder(int rowMax);
void leftAndRightOfBorder(int colMax, int rowMax);
void downOfBorder(int rowMax);

int main()
{
    initscr();

    char direction;
    int row;
    int col;
    char lastDirection;
    int randomRow;
    int randomCol;
    const int ROW_MAX = 50;
    const int COL_MAX = 35;

    drawGameBorder(ROW_MAX, COL_MAX);

    srand(time(0));

    row = getStartPointRowCoordination();
    col = getStartPointColCoordination();

    lastDirection = '7';

    makeRandomStarCoordination(&randomRow, &randomCol, ROW_MAX, COL_MAX);

    move(randomRow, randomCol);
    printw("*");
    move(row, col);
    refresh();

    printw(".");   

    refresh();
    
    while (true)
    {
        direction = getDirection();
        printDirection(direction, &lastDirection, &row, &col, &randomRow, &randomCol, ROW_MAX, COL_MAX);
    }

    getch();

    endwin();

    return 0;
}

void makeRandomStarCoordination(int *row, int *col, int rowMax, int colMax)
{
    *row = (rand() % rowMax) + 1;
    *col = (rand() % colMax) + 1;
}

int getStartPointRowCoordination()
{
    return 15;
}

int getStartPointColCoordination()
{
    return 35;
}

char getDirection()
{
    char direction;

    cin >> direction;

    return direction;
}

void printDirection(char direction, char *lastDirection, int *row, int *col, int *randomRow, int *randomCol, int rowMax, int colMax)
{
    if (direction == 'w' || direction == 'W')
    {
        if (*lastDirection == 's' || *lastDirection == 'S')
        {
            return;
        }

        printUp(row, col);
        *lastDirection = direction;

        if (*row == *randomRow && *col == *randomCol)
        {
            makeRandomStarCoordination(randomRow, randomCol, rowMax, colMax);

            move(*randomRow, *randomCol);
            printw("*");
            move(*row, *col);
            refresh();
        }
    }
    else
    {
        if (direction == 's' || direction == 'S')
        {
            if (*lastDirection == 'w' || *lastDirection == 'W')
            {
                return;
            }
            printDown(row, col);
            *lastDirection = direction;

            if (*row == *randomRow && *col == *randomCol)
            {
                makeRandomStarCoordination(randomRow, randomCol, rowMax, colMax);

                move(*randomRow, *randomCol);
                printw("*");
                move(*row, *col);
                refresh();
            }
        }
        else
        {
            if (direction == 'd' || direction == 'D')
            {
                if (*lastDirection == 'a' || *lastDirection == 'A')
                {
                    return;
                }
                printRight(row, col);
                *lastDirection = direction;

                if (*row == *randomRow && *col == *randomCol)
                {
                    makeRandomStarCoordination(randomRow, randomCol, rowMax, colMax);

                    move(*randomRow, *randomCol);
                    printw("*");
                    move(*row, *col);
                    refresh();
                }
            }
            else
            {
                if (direction == 'a' || direction == 'A')
                {
                    if (*lastDirection == 'd' || *lastDirection == 'D')
                    {
                        return;
                    }
                    printLeft(row, col);
                    *lastDirection = direction;

                    if (*row == *randomRow && *col == *randomCol)
                    {
                        makeRandomStarCoordination(randomRow, randomCol, rowMax, colMax);

                        move(*randomRow, *randomCol);
                        printw("*");
                        move(*row, *col);
                        refresh();
                    }
                }
            }
        }
    }
}

void printUp(int *row, int *col)
{
    *row = *row - 1;
    move(*row, *col);
    printw(".");
    move(*row, *col);
    refresh();
}

void printDown(int *row, int *col)
{
    *row = *row + 1;
    move(*row, *col);
    printw(".");
    move(*row, *col);
    refresh();
}

void printRight(int *row, int *col)
{
    *col = *col + 1;
    move(*row, *col);
    printw(".");
    move(*row, *col);
    refresh();
}

void printLeft(int *row, int *col)
{
    *col = *col - 1;
    move(*row, *col);
    printw(".");
    move(*row, *col);
    refresh();
}

void drawGameBorder(int rowMax, int colMax)
{
    upOfBorder(rowMax);
    leftAndRightOfBorder(colMax, rowMax);
    downOfBorder(rowMax);
    refresh();    
}

void upOfBorder(int rowMax)
{
    for (int row = 0; row < rowMax; row++)
    {
        printw(". ");
    }
}

void leftAndRightOfBorder(int colMax, int rowMax)
{
    printw("\n");

    for (int col = 0; col < colMax; col++)
    {
        printw(".");
       
        for (int space = 0; space < rowMax * 2 - 3; space ++)
        {
            printw(" ");
        }
        
        printw(".");
        printw("\n");
    }
}

void downOfBorder(int rowMax)
{
    for (int row = 0; row < rowMax; row++)
    {
        printw(". ");
    }   
}
