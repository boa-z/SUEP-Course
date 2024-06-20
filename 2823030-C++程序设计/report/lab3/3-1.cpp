#include <iostream>
using namespace std;

class Date {
private:
    int year;
    int month;
    int day;
public:
    Date(int y=2023, int m=3, int d=27) : year(y), month(m), day(d) {}

    Date(Date& c) : year(c.year), month(c.month), day(c.day) {}

        void print() const {
        cout << year << "年" << month << "月" << day << "日" <<endl;
        }
        void setDate(int y, int m, int d) {
        year = y;
        month = m;
        day = d;
        }
        void guiyear(){
                if(year%4==0) cout<<year<<"年是闰年";
    else cout<<year<<"年不是闰年";
}
    
};


int main() {
    Date t;
    t.print();
    t.setDate(2022, 3, 27);
    t.guiyear();
    return 0;
}
