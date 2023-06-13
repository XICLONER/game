#include <iostream>
#include <ncurses.h>

using namespace std;

int getStartPointRowCoordination();
int getStartPointColCoordination();
void moveCurser(int row, int col);
char getDirection();
void printDirection(char direction, int *row, int *col);
void printError();
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

    row = getStartPointRowCoordination();
    col = getStartPointColCoordination();

    moveCurser(row, col);

    printw(".");

    refresh();

    while (true)
    {
        direction = getDirection();

        printDirection(direction, &row, &col);
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

void printDirection(char direction, int *row, int *col)
{
    if (direction == 'w' || direction == 'W')
    {
        printUp(row, col);
    }
    else
    {
        if (direction == 's' || direction == 'S')
        {
            printDown(row, col);
        }
        else
        {
            if (direction == 'd' || direction == 'D')
            {
                printRight(row, col);
            }
            else
            {
                if (direction == 'a' || direction == 'A')
                {
                    printLeft(row, col);
                }
                else
                {
                    printError();
                }
            }
        }
    }
}

void printError()
{
    cout << "Wrong character! use thise keys (w.s.d.a)\n";
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