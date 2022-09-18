#include<iostream>
using namespace std;
int main()
{
    string a;
    cin>>a;
    for (lol i= 0; i < a.size(); i++)
    {  if (a[i]=='.')
    {
       cout<<0;
    } 
    if (a[i]== '-'&&a[i+1]=='.')
    {
       cout<<1;
       i++;
    }
    if (a[i]== '-'&&a[i+1]=='-')
    {
       cout<<2;
       i++;
    }
    
    
    
     
    }
     
}