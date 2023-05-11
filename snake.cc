#include <iostream>
using namespace std;

int main()
{
    char directions[] = {'w', 'W', 's', 'S', 'd', 'D', 'a', 'A'};
    char input;

    cout << "Which direction? (w , s , d , a):\n";
    cin >> input;

    if (input == directions[0] || input == directions[1])
    {
        cout << "Up\n";
        return 0;
    }

    if (input == directions[2] || input == directions[3])
    {
        cout << "Down\n";
        return 0;
    }

    if (input == directions[4] || input == directions[5])
    {
        cout << "Right\n";
        return 0;
    }

    if (input == directions[6] || input == directions[7])
    {
        cout << "Left\n";
        return 0;
    }

    cout << "please choose a character between (w,s,d,a) your fucking ( " << input << " ) is not between them\n";
}