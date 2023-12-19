#include <iostream>
#include <string>
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

    Date(const Date &c) : year(c.year), month(c.month), day(c.day)
    {
    }
    void print() const
    {
        cout << year << "年" << month << "月" << day << "日";
    }
};

class People
{
private:
    int pid;
    string sname;
    char sex;
    Date birthday;
    string address;

public:
    People(int id, string name, char se, Date bir, string addr) : pid(id), sname(name), sex(se), birthday(bir), address(addr) {}
    People(const People &d) : pid(d.pid), sname(d.sname), sex(d.sex), birthday(d.birthday), address(d.address) {}
    People() {}
    void showPeople()
    {
        cout << "编号" << pid << "，姓名" << sname << "，性别";
        if (sex == 'M')
            cout << "男";
        else if (sex == 'F')
            cout << "女";
        else
            cout << "err";
        cout << "，地址" << address << "，出生于";
        birthday.print();
        cout << endl;
    }

    void change_address(string new_address)
    {
        address = new_address;
    }
};

int main()
{
    Date d1(1453, 5, 29);
    People Q[2] = {People(1001, "张三", 'M', d1, "君士坦丁堡"), People(1002, "李四", 'F', d1, "科斯坦丁尼耶")};

    for (int i = 0; i < 2; i++)
        Q[i].showPeople();

    int n;
    cout << "请输入人数: ";
    cin >> n;
    People *P = new People[n];
    for (int i = 0; i < n; i++)
    {
        int id;
        string name;
        char se;
        int y, m, d;
        string addr;
        cout << "请输入第" << i + 1 << "个人的信息: ";
        cin >> id >> name >> se >> y >> m >> d >> addr;
        Date bir(y, m, d);
        P[i] = People(id, name, se, bir, addr);
    }
    for (int i = 0; i < n; i++)
        P[i].showPeople();
    delete[] P;
}