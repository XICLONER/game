#include <iostream>
#include <ncurses.h>

using namespace std;

int printUp(char input);
int printDown(char input);
int printRight(char input);
int printLeft(char input);
void errorWrongCharacter(char input);
int checkInputDirection(char input);

int main()
{
    initscr();
    noecho();
    cbreak();

    char input;
    int row = 10;
    int col = 30;

    cout << "Press a key to start:";
    cin >> input;

    move(row, col);
    printw(".");

    checkInputDirection(input);

    return 0;
}

int printUp(char input)
{
    int row = 10;
    int col = 30;

    move(row - 1, col);
    printw(".");
    refresh();
    getch();
    endwin();

    return 0;
}

int printDown(char input)
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

int printRight(char input)
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

int printLeft(char input)
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

void errorWrongCharacter(char input)
{
    cout << " please choose a character between (w,s,d,a) your fucking ( " << input << " ) is not between them.\n";

    endwin();
}

int checkInputDirection(char input)
{

    char directions[] = {'w', 'W', 's', 'S', 'd', 'D', 'a', 'A'};

    if (input == directions[0] || input == directions[1])
    {

        printUp(input);
    }

    if (input == directions[2] || input == directions[3])
    {
        printDown(input);
    }

    if (input == directions[4] || input == directions[5])
    {
        printRight(input);
    }

    if (input == directions[6] || input == directions[7])
    {
        printLeft(input);
    }

    errorWrongCharacter(input);

    return 0;
}
