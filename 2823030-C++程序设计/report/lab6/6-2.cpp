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
        cout<<endl;
    }

    void change_address(string new_address)
    {
        address = new_address;
    }
};

class Student : virtual public People
{
protected:
    string major;
    string classno;
    Date endate;

public:
    Student(int id, string name, char se, Date bir, string addr, string maj, string cno, Date en) : People(id, name, se, bir, addr), major(maj), classno(cno), endate(en) {}
    void showStudent()
    {
        showPeople();
        cout << "专业" << major << "，班级编号" << classno << "，入学日期";
        endate.print();
        cout<<endl;
    }
};

class Teacher : virtual public People
{
protected:
    string department;
    string profession;

public:
    Teacher(int id, string name, char se, Date bir, string addr, string dep, string pro) : People(id, name, se, bir, addr), department(dep), profession(pro) {}
    void showTeacher()
    {
        showPeople();
        cout << "学院" << department << "，职称" << profession << endl;
    }
};


class ST : public Student, public Teacher
{
private:
    string adv_name;
    string research;

public:
    ST(int id, string name, char se, Date bir, string addr,
       string maj, string cno, Date en,
       string dep, string pro,
       string advn, string res) : People(id,name,se,bir,addr),
                                   Student(id,name,se,bir,addr,maj,cno,en),
                                   Teacher(id,name,se,bir,addr,dep,pro),
                                   adv_name(advn), research(res) {}
    void showST()
    {
        showPeople();
        cout << "专业" << major << "，班级编号" << classno << "，入学日期";
        endate.print();
        cout << "，学院" << department << "，职称" << profession;
        cout << "，导师姓名" << adv_name << "，研究方向" << research;
        cout<<endl;
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

    Date d2(2023, 9 ,1);
    Student s1(1003,"王八",'M',d1,"北京","计算机科学与技术","计算机1701",d2);
    s1.showStudent();

    Teacher t1(1004,"赵云",'F',d1,"上海","计算机学院","副教授");
    t1.showTeacher();

    ST st1(1005,"金金金",'M',d1,"广州","计算机科学与技术","计算机1702",d2,"计算机学院","助教","赵云","AICG");
    st1.showST();
}
