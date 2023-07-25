#include <iostream>
#include <ncurses.h>
#include <cstdlib>

using namespace std;

int getStartPointRowCoordination();
int getStartPointColCoordination();
void moveCurser(int row, int col);
char getDirection();
void printDirection(char direction, char *lastDirection, int *row, int *col, int *randomRow, int *randomCol, int rowMax, int colMax);
void printUp(int *row, int *col);
void printDown(int *row, int *col);
void printRight(int *row, int *col);
void printLeft(int *row, int *col);
void newRandomStar(int *row, int *col, int rowMax, int colMax);
void gameBorder(int starRowMax, int starColMax);
void upOfBorder(int starRowMax);
void leftAndRightOfBorder(int starColMax);
void downOfBorder(int starRowMax);

int main()
{
    initscr();

    char direction;
    int row;
    int col;
    char lastDirection;
    int randomRow;
    int randomCol;
    const int ROW_MAX = 40;
    const int COL_MAX = 20;

    const int STAR_ROW_MAX = 50;
    const int STAR_COL_MAX = 35;

    gameBorder(STAR_ROW_MAX, STAR_COL_MAX);

    srand(time(0));

    newRandomStar(&randomRow, &randomCol, ROW_MAX, COL_MAX);

    move(randomRow, randomCol);
    printw("*");

    lastDirection = '7';

    row = getStartPointRowCoordination();
    col = getStartPointColCoordination();

    moveCurser(row, col);

    printw(".");
    printw(".");
    printw(".");
    printw(".");

    move(row, col);

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

void newRandomStar(int *row, int *col, int rowMax, int colMax)
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
            newRandomStar(randomRow, randomCol, rowMax, colMax);

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
                newRandomStar(randomRow, randomCol, rowMax, colMax);

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
                    newRandomStar(randomRow, randomCol, rowMax, colMax);

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
                        newRandomStar(randomRow, randomCol, rowMax, colMax);

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
    moveCurser(*row, *col);
    printw(".");
    move(*row, *col);
    refresh();
}

void printDown(int *row, int *col)
{
    *row = *row + 1;
    moveCurser(*row, *col);
    printw(".");
    move(*row, *col);
    refresh();
}

void printRight(int *row, int *col)
{
    *col = *col + 1;
    moveCurser(*row, *col);
    printw(".");
    move(*row, *col);
    refresh();
}

void printLeft(int *row, int *col)
{
    *col = *col - 1;
    moveCurser(*row, *col);
    printw(".");
    move(*row, *col);
    refresh();
}

void gameBorder(int starRowMax, int starColMax)
{
    upOfBorder(starRowMax);
    leftAndRightOfBorder(starColMax);
    downOfBorder(starRowMax);
}

void upOfBorder(int starRowMax)
{
      for (int row = 0; row < starRowMax; row++)
    {
        printw(". ");
        refresh();
    }
}

void leftAndRightOfBorder(int starColMax)
{
        printw("\n");
     for (int col = 0; col < starColMax; col++)
    {
        printw(".");
        printw("                                                                                                 ");
        printw(".");
        printw("\n");
        refresh();
    }
}

void downOfBorder(int starRowMax)
{
     for (int row = 0; row < starRowMax; row++)
    {
        printw(". ");
        refresh();    
    }   
}
