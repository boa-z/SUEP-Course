#include<iostream>
using namespace std;
int x=1,y=2;

void fnl()
{  
  int y=200;
  static int z=100;
  x++;
  y++;
  z++;
cout <<"x="<<x<<endl;
  cout<<"y="<<y<<endl;
cout<<"z="<<z<<endl;
}

int main()
{   
  cout<<"Begin．．．"<<endl;
  cout<<"x="<<x<<endl;
  cout<<"y="<<y<<endl;

  cout<<"Evaluate x and y in main()…"<<endl;
  int x=10,y=20;
  cout<<"x="<<x<<endl;
  cout<<"y="<<y<<endl;

  cout<<"Step into fnl()…"<<endl;
  fnl();

cout<<"Step into fnl()  again…"<<endl;
  fnl();

  cout<<"Back in main"<<endl;
  cout<<"x="<<x<<endl;
  cout<<"y="<<y<<endl;
  return 0;
}