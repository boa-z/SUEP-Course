#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;
int main()
{
    int a, b = -1, c = 0;
    a = 100 + rand() % 100;
    while (b != a)
    {
        cout << "请输入数" << endl;
        cin >> b;
        c++;
        if (b > a)
        {
            cout << "猜大了" << endl;
        }
        else if (b < a)
        {
            cout << "猜小了" << endl;
        }
        else
        {
            cout << "猜对了" << endl;
            break;
        }
    }
    cout << "次数为" << c << endl;
    return 0;
}