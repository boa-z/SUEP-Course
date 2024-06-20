#include <iostream>
using namespace std;

class WangPo
{
public:
    static int totalWeight;
    static int totalCount;

    static void sell(int weight)
    {
        totalWeight += weight;
        totalCount++;
    }

    static void refund(int weight)
    {
        totalWeight -= weight;
        totalCount--;
    }
};

int WangPo::totalWeight = 0;
int WangPo::totalCount = 0;

int main()
{
    WangPo::sell(10);
    WangPo::sell(20);
    WangPo::refund(10);
    WangPo::sell(20);

    cout << "Total weight sold: " << WangPo::totalWeight << endl;
    cout << "Total count sold: " << WangPo::totalCount << endl;

    return 0;
}