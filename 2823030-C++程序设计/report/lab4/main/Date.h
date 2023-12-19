#ifndef DATE_H
#define DATE_H

#include <iostream>
using namespace std;

class Date {
private:
    int year;
    int month;
    int day;

public:
    Date(int y = 2023, int m = 3, int d = 27);
    Date(Date &c);
    void print() const;
};

#endif