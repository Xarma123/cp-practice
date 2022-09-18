#include<iostream>
#include<conio.h>
using namespace std;
int main(){
    lol a , r ,x , y=1,s=0;
    cin>>a;
    while (a>0)
    {r=a%10;
    a=a/10;
    x=r*y;
    y=y*2; 
    s=s+x;}
    cout<<s;
    getch();
    return 0;}