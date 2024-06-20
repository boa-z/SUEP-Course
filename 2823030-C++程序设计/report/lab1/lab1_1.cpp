#include <iostream>
using namespace std;
int main()
{
    int a, b, c;
    for (a = 2; a <= 100; a++)
    {
        c = 1;
        for (b = 2; b < a; b++)
        {
            if (a % b == 0)
            {
                c = 0;
                break;
            }
        }
        if (c != 0)
        {
            cout << a << endl;
        }
    }

    return 0;
}