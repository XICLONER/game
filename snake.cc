#include <iostream>
#include <ncurses.h>
#include <cstdlib>

using namespace std;

int getStartPointRowCoordination();
int getStartPointColCoordination();
void moveCurser(int row, int col);
char getDirection();
void printDirection(char direction, char *lastDirection, int *row, int *col, int *randomRow, int *randomCol);
void printUp(int *row, int *col);
void printDown(int *row, int *col);
void printRight(int *row, int *col);
void printLeft(int *row, int *col);

int main()
{
    initscr();

    char direction;
    int row;
    int col;
    char lastDirection;
    int randomRow;
    int randomCol;

    srand(time(0));

    randomRow = (rand() % 30) + 1;
    randomCol = (rand() % 100) + 1;

    move(randomRow, randomCol);
    printw("*");

    lastDirection = '7';

    row = getStartPointRowCoordination();
    col = getStartPointColCoordination();

    moveCurser(row, col);

    printw(".");

    refresh();

    while (true)
    {
        direction = getDirection();
        printDirection(direction, &lastDirection, &row, &col, &randomRow, &randomCol);
    }

    getch();

    endwin();

    return 0;
}

int getStartPointRowCoordination()
{
    return 15;
}

int getStartPointColCoordination()
{
    return 35;
}

void moveCurser(int row, int col)
{
    move(row, col);
}

char getDirection()
{
    char direction;

    cin >> direction;

    return direction;
}

void printDirection(char direction, char *lastDirection, int *row, int *col, int *randomRow, int *randomCol)
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
            *randomRow = (rand() % 50) + 1;
            *randomCol = (rand() % 150) + 1;

            move(*randomRow, *randomCol);
            printw("*");
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
                *randomRow = (rand() % 50) + 1;
                *randomCol = (rand() % 150) + 1;

                move(*randomRow, *randomCol);
                printw("*");
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
                    *randomRow = (rand() % 50) + 1;
                    *randomCol = (rand() % 150) + 1;

                    move(*randomRow, *randomCol);
                    printw("*");
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
                        *randomRow = (rand() % 50) + 1;
                        *randomCol = (rand() % 150) + 1;

                        move(*randomRow, *randomCol);
                        printw("*");
                    }
                }
            }
        }
    }
}

void printUp(int *row, int *col)
{
    *row = *row - 1;
    moveCurser(*row, *col);
    printw(".");
    refresh();
}

void printDown(int *row, int *col)
{
    *row = *row + 1;
    moveCurser(*row, *col);
    printw(".");
    refresh();
}

void printRight(int *row, int *col)
{
    *col = *col + 1;
    moveCurser(*row, *col);
    printw(".");
    refresh();
}

void printLeft(int *row, int *col)
{
    *col = *col - 1;
    moveCurser(*row, *col);
    printw(".");
    refresh();
}