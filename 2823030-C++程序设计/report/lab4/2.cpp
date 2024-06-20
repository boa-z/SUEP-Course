#include <iostream>
using namespace std;

class Watermelon {
public:
    Watermelon(double w) : weight(w) {
        total_weight += w;
        total_number++;
    }
    void refund() {
        total_weight -= weight;
        total_number--;
    }
    double get_weight() { return weight; }
    double get_price() { return weight * price; }
    static void total_disp() {
        cout << "总重量: " << total_weight << endl;
        cout << "总个数: " << total_number << endl;
        cout << "总金额: " << total_weight * price << endl;
    }

private:
    double weight;
    static double total_weight;
    static int total_number;
    static const double price;
};

double Watermelon::total_weight = 0;
int Watermelon::total_number = 0;
const double Watermelon::price = 2.5;

int main() {
    Watermelon w1(3.2);
    Watermelon w2(4.1);
    Watermelon w3(2.7);
    w2.refund();
    Watermelon::total_disp();
}