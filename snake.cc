#include <iostream>
#include <ncurses.h>

using namespace std;

int directions(char input)
{

    char directions[] = {'w', 'W', 's', 'S', 'd', 'D', 'a', 'A'};

    if (input == directions[0] || input == directions[1])
    {

        move(9, 30);

        printw(".");

        refresh();

        getch();

        endwin();

        return 0;
    }

    if (input == directions[2] || input == directions[3])
    {
        move(11, 30);

        printw(".");

        refresh();

        getch();

        endwin();
        return 0;
    }

    if (input == directions[4] || input == directions[5])
    {
        move(10, 31);

        printw(".");

        refresh();

        getch();

        endwin();
        return 0;
    }

    if (input == directions[6] || input == directions[7])
    {
        move(10, 29);

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

    char input;

    cout << "Which direction? (w , s , d , a):";
    cin >> input;

    move(10, 30);
    printw(".");

    directions(input);

    return 0;
}