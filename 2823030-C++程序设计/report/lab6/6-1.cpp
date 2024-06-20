#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Shape
{
public:
    Shape(string c) 
    { color=c; cout<<"Shape"<<endl;} 
    Shape(Shape &S) 
    {color=S.color; cout<<"copy Shape"<<endl;}
    ~Shape() 
    { cout<<"~Shape"<<endl;}
    void print()
    { cout<<"color:"<<color<<endl;}
private:
    string color;
};

class Rectangle: public Shape
{
public:
    Rectangle(double w, double h,string c):Shape(c)
    { width=w; height=h; cout<<"Rectangle"<<endl;}
    Rectangle(Rectangle &R):Shape(R)
    { width =R.width; height=R.height; cout<<"copy Rectangle"<<endl;}
    ~Rectangle()
    {cout<<"~Rectangle"<<endl;} 
    double getArea() const
    { return width*height; } 
protected: 
    double width,height;
};

class Circle: public Shape
{
public:
    Circle(double r,string c):Shape(c)
    { radius=r; cout<<"Circle"<<endl;}
    Circle(Circle &C):Shape(C)
    { radius =C.radius; cout<<"copy Circle"<<endl;}
    ~Circle()
    {cout<<"~Circle"<<endl;} 
    double getArea() const
    { return M_PI*radius*radius; } 
protected: 
    double radius;
};

int main()
{ 
    Rectangle r(3,4,"RED");
    r.print();
    cout<<"Rectangle area:"<<r.getArea()<<endl;
    
    Rectangle r1=r;
    r1.print();
    cout<<"Rectangle area:"<<r1.getArea()<<endl;
    
    Circle c(5,"BLUE");
    c.print();
    cout<<"Circle area:"<<c.getArea()<<endl;
    
    Circle c1=c;
    c1.print();
    cout<<"Circle area:"<<c1.getArea()<<endl;
    
 return 0;
}
