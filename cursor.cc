#include <ncurses.h>

int main()
{
    initscr();
    cbreak();
    noecho();

    move(13, 11);

    printw("*");

    refresh();

    getch();

    endwin();

    return 0;
}
