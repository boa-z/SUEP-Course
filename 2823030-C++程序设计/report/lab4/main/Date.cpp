#include "Date.h"

Date::Date(int y, int m, int d) : year(y), month(m), day(d) {}

Date::Date(Date &c) : year(c.year), month(c.month), day(c.day) {}

void Date::print() const {
    cout << year << "年" << month << "月" << day << "日" << endl;
}