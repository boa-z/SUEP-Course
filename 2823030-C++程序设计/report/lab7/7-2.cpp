#include <iostream>
using namespace std;

class Point {
private:
    int x, y;
public:
    Point(int x = 0, int y = 0) : x(x), y(y) {}
    Point& operator++() {
        ++x;
        ++y;
        return *this;
    }
    Point operator--(int) {
        Point temp = *this;
        --x;
        --y;
        return temp;
    }
    friend ostream& operator<<(ostream& os, const Point& p);
};

ostream& operator<<(ostream& os, const Point& p) {
    os << '(' << p.x << ',' << p.y << ')';
    return os;
}

int main() {
    Point p1(1, 2);
    cout << p1 << endl;
    ++p1;
    cout << p1 << endl;
    p1--;
    cout << p1 << endl;
    return 0;
}
