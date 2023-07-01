#include <iostream>
#include <ncurses.h>
#include <cstdlib>

using namespace std;

int getStartPointRowCoordination();
int getStartPointColCoordination();
void moveCurser(int row, int col);
char getDirection();
void printDirection(char direction, char *lastDirection, int *row, int *col);
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

    lastDirection = '7';

    row = getStartPointRowCoordination();
    col = getStartPointColCoordination();

    srand(time(0));
    moveCurser(row, col);

    printw(".");

    refresh();

    while (true)
    {

        direction = getDirection();
        printDirection(direction, &lastDirection, &row, &col);

        randomRow = (rand() % 50) + 1;
        randomCol = (rand() % 150) + 1;

        move(randomRow, randomCol);
        printw("*");
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

void printDirection(char direction, char *lastDirection, int *row, int *col)
{
    if (direction == 'w' || direction == 'W')
    {
        if (*lastDirection == 's' || *lastDirection == 'S')
        {
            return;
        }

        printUp(row, col);
        *lastDirection = direction;
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