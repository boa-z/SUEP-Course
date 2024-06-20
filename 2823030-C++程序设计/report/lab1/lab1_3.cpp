#include <iostream>
using namespace std;
const double PI = 3.1416;
int main()
{
     int iType;
     float r, a, b, area;
     cout << "图形的类型为？（1-正方形 2- 长方形 3-圆形）:";
     cin >> iType;
     switch (iType)
     {
     case 1:
          cout << "正方形的边长为:";
          cin >> a;
          area = a * a;
          cout << "面积为:" << area << endl;
          break;
     case 2:
          cout << "长方形的长为:";
          cin >> a;
          cout << "长方形的宽为:";
          cin >> b;
          area = a * b;
          cout << "面积为:" << area << endl;
          break;
     case 3:
          cout << "圆形的半径为:";
          cin >> r;
          area = r * r * PI;
          cout << "面积为:" << area << endl;
          break;
     default:
          cout << "不是合法的输入值！" << endl;
          break;
     }
     return 0;
}