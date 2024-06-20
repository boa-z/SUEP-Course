#include <iostream>
using namespace std;
class Date
{
private:
    int year;
    int month;
    int day;

public:
    Date(int y = 2023, int m = 3, int d = 27) : year(y), month(m), day(d)
    {
    }

    Date(Date &c) : year(c.year), month(c.month), day(c.day)
    {
    }
    void print() const
    {
        cout << year << "年" << month << "月" << day << "日" << endl;
    }
};

class People
{
private:
    int pid;
    char sex;
    Date birthday;

public:
    People(int id, char se, Date bir) : pid(id), sex(se), birthday(bir){}
    People(People &d) : pid(d.pid), sex(d.sex), birthday(d.birthday) {}

    void print()
    {
        cout << "编号" << pid << "，性别" ;
        if(sex=='M') cout<<"男";
        else if(sex=='F') cout<<"女";
        else cout<<"err";
        cout<< "，出生于";
        birthday.print();
    }
};

int main()
{
    Date d1(2000, 1, 1);
    People P(1000, 'M', d1);
    P.print();
    return 0;
}
