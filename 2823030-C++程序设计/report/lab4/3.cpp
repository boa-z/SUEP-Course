#include <iostream>
using namespace std;

class Car;

class Boat {
public:
    Boat(int w) : weight(w) {}
    friend int getTotalWeight(Boat &b, Car &c);
private:
    int weight;
};

class Car {
public:
    Car(int w) : weight(w) {}
    friend int getTotalWeight(Boat &b, Car &c);
private:
    int weight;
};

int getTotalWeight(Boat &b, Car &c) {
    return b.weight + c.weight;
}

int main() {
    Boat b(100);
    Car c(200);
    cout << "weight: " << getTotalWeight(b, c) << endl;
    return 0;
}