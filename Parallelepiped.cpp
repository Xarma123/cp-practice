#include<iostream>
#include<cmath>
using namespace std;
int main()
{  float c1,c2,c3;
  cin>>c1>>c2>>c3;
  cout<<4*( sqrt((c2*c3)/c1) + sqrt((c1*c3)/c2)  + sqrt((c1*c2)/c3)        );

}