#include "People.h"

People::People(int id, char se, Date bir) : pid(id), sex(se), birthday(bir) {}

People::People(People &d) : pid(d.pid), sex(d.sex), birthday(d.birthday) {}

void People::print() {
    cout << "编号" << pid << "，性别";
    if (sex == 'M') cout << "男";
    else if (sex == 'F') cout << "女";
    else cout << "err";
    cout << "，出生于";
    birthday.print();
}