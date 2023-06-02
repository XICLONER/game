#include <iostream>
#include <ncurses.h>

using namespace std;

int getUpDirection(char input)
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

int getDownDirection(char input)
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

int getRightDirection(char input)
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

int getLeftDirection(char input)
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

void checkWrongCharacter(char input)
{
    cout << " please choose a character between (w,s,d,a) your fucking ( " << input << " ) is not between them.\n";

    endwin();
}

int checkInputDirection(char input)
{

    char directions[] = {'w', 'W', 's', 'S', 'd', 'D', 'a', 'A'};

    if (input == directions[0] || input == directions[1])
    {

        getUpDirection(input);
    }

    if (input == directions[2] || input == directions[3])
    {
        getDownDirection(input);
    }

    if (input == directions[4] || input == directions[5])
    {
        getRightDirection(input);
    }

    if (input == directions[6] || input == directions[7])
    {
        getLeftDirection(input);
    }

    checkWrongCharacter(input);

    return 0;
}

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