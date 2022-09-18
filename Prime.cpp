#include<iostream>
#include<conio.h>
using namespace std;
int main( )
{

lol a,b=2,c;
cin>>a;
if (a==1)
{
    cout<<"not prime";
}else
{
    



while (c!=0&&b<a)
{  c=a%b;
    b++;
}
if (c==0)
{
    cout<<"not a prime no";
}


else
{
    cout<<"prime no ";
}
}
getch();
return 0;




}