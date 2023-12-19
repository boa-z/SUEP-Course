#ifndef PEOPLE_H
#define PEOPLE_H

#include "Date.h"

class People {
private:
    int pid;
    char sex;
    Date birthday;

public:
    People(int id, char se, Date bir);
    People(People &d);
    void print();
};

#endif