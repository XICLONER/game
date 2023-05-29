#include <iostream>
#include <ncurses.h>

using namespace std;

int directions(char input)
{
    int row = 10;
    int col = 30;
    char directions[] = {'w', 'W', 's', 'S', 'd', 'D', 'a', 'A'};

    if (input == directions[0] || input == directions[1])
    {

        move(row - 1, col);

        printw(".");

        refresh();

        getch();

        endwin();

        return 0;
    }

    if (input == directions[2] || input == directions[3])
    {
        move(row + 1, col);

        printw(".");

        refresh();

        getch();

        endwin();

        return 0;
    }

    if (input == directions[4] || input == directions[5])
    {
        move(row, col + 1);

        printw(".");

        refresh();

        getch();

        endwin();

        return 0;
    }

    if (input == directions[6] || input == directions[7])
    {
        move(row, col - 1);

        printw(".");

        refresh();

        getch();

        endwin();

        return 0;
    }

    cout << " please choose a character between (w,s,d,a) your fucking ( " << input << " ) is not between them.\n";

    endwin();

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

    cout << "Which direction? (w , s , d , a):";
    cin >> input;

    move(row, col);
    printw(".");

    directions(input);

    return 0;
}