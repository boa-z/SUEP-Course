#include<iostream>
using namespace std;
const double p=3.14159265;
double area(double r)
{
return p*r*r;
}
double area(double a ,double b)
{
return a*b;
}
int main()
{
double x,y;
cout<<"请输入矩形的长：";
cin>>x;
cout<<"请输入矩形的宽：";
cin>>y;
cout<<"矩形的面积为："<<area(x,y)<<endl;
double z;
cout<<"请输入圆的半径：";
cin>>z;
cout<<"圆的面积为："<<area(z)<<endl;
return 0;
}