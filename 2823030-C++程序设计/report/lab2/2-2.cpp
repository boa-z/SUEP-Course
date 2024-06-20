#include <iostream>
using namespace std;
int fb(int n){
    int f;
    if(n==1||n==2)
    return 1;
    else f=fb(n-1)+fb(n-2);
    return f;
}
int main()
{
    int n;
    cout<<"输入第n项"<<endl;
    cin>>n;
    cout<<"fb函数值为"<<fb(n)<<endl;
}