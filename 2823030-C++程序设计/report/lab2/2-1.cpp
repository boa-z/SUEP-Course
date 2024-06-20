#include <iostream>
using namespace std;
float temp(float f){
    float c;
    c=5*(f-32)/9;
    return c;
}
int main()
{
    float f;
    cout<<"输入一个华氏温度"<<endl;
    cin>>f;
    cout<<"事"<<temp(f)<<endl;
}