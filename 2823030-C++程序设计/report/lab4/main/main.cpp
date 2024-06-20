#include <iostream>
#include "People.h"
using namespace std;

int main() {
    Date d1(2000, 1, 1);
    People P(1000, 'M', d1);
    P.print();
    return 0;
}