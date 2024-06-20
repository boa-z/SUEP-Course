#include <iostream>
using namespace std;

class shape
{
public:
    shape()
    {
        cout << "shape" << endl;
    }
    virtual ~shape()
    {
        cout << "~shape" << endl;
    }
    virtual float getarea() = 0;
};

class Circle: public shape
{
public:
    Circle(float r):radius(r)
    {
        cout << "Circle" << endl;
    }
    ~Circle()
    {
        cout << "~Circle" << endl;
    }
    float getarea()
    {
        return 3.14 * radius * radius;
    }
private:
    float radius;
};

class Rectangle: public shape
{
public:
    Rectangle(float w, float h):width(w), height(h)
    {
        cout << "Rectangle" << endl;
    }
    ~Rectangle()
    {
        cout << "~Rectangle" << endl;
    }
    float getarea()
    {
        return width * height;
    }
private:
    float width;
    float height;
};

int main()
{
    shape *sp;
    
    sp = new Circle(5);
    cout << "The area of the Circle is " << sp->getarea() << endl;
    delete sp;

    sp = new Rectangle(4, 5);
    cout << "The area of the Rectangle is " << sp->getarea() << endl;
    delete sp;

    return 0;
}
