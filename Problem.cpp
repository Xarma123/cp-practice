#include<iostream>
using namespace std;
int main()
{
    string a;
    cin>>a;
    for (lol i = 0; a[i]!='\0'; i++)
    {    if (a[i]>=53)
    {  
          if(!(i==0&&a[i]==57))
          a[i]=57-a[i]+48;

    
    } 
   
    
         
    } cout<<a;
    
}