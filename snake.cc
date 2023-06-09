#include <iostream>
#include <ncurses.h>

using namespace std;

int getStartPointRowCordination();
int getStartPointColCordination();
void moveCurser(int row, int col);
char getDirection();
void printDirection(char direction, int row, int col);
void printError();
void printUp(int row, int col);
void printDown(int row, int col);
void printRight(int row, int col);
void printLeft(int row, int col);

int main()
{
    initscr();

    char direction;
    int row;
    int col;

    row = getStartPointRowCordination();
    col = getStartPointColCordination();

    moveCurser(row, col);

    printw(".");

    refresh();

    direction = getDirection();

    printDirection(direction, row, col);

    direction = getDirection();

    printDirection(direction, row, col);

    getch();

    endwin();

    return 0;
}

int getStartPointRowCordination()
{
    return 15;
}

int getStartPointColCordination()
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

void printDirection(char direction, int row, int col)
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

void printUp(int row, int col)
{
    moveCurser(row - 1, col);
    printw(".");
    refresh();
}

void printDown(int row, int col)
{
    moveCurser(row + 1, col);
    printw(".");
    refresh();
}

void printRight(int row, int col)
{
    moveCurser(row, col + 1);
    printw(".");
    refresh();
}

void printLeft(int row, int col)
{
    moveCurser(row, col - 1);
    printw(".");
    refresh();
}
/*int printDown(char character)
{
    int row = 10;
    int col = 30;

    move(row + 1, col);
    printw(".");
    refresh();
    getch();
    endwin();

    return 0;
}

int printRight(char character)
{
    int row = 10;
    int col = 30;

    move(row, col + 1);
    printw(".");
    refresh();
    getch();
    endwin();

    return 0;
}

int printLeft(char character)
{
    int row = 10;
    int col = 30;

    move(row, col - 1);
    printw(".");
    refresh();
    getch();
    endwin();

    return 0;
}

void errorWrongCharacter(char character)
{
    cout << " please choose a character between (w,s,d,a) your fucking ( " << character << " ) is not between them.\n";

    endwin();
}

int printDirection(char character)
{

    char directions[] = {'w', 'W', 's', 'S', 'd', 'D', 'a', 'A'};

    if (character == directions[0] || character == directions[1])
    {

        printUp(character);
    }

    if (character == directions[2] || character == directions[3])
    {
        printDown(character);
    }

    if (character == directions[4] || character == directions[5])
    {
        printRight(character);
    }

    if (character == directions[6] || character == directions[7])
    {
        printLeft(character);
    }

    errorWrongCharacter(character);

    return 0;
}*/
