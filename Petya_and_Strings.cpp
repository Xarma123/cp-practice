#include<bits/stdc++.h>
using namespace std;
int main()
{
    string a , b ;
    cin>>a>>b;
       transform(a.begin(), a.end(), a.begin(), ::toupper);
            transform(b.begin(), b.end(), b.begin(), ::toupper);
   lol n =  a.compare(b);
   if(n>0)
   cout<<1;
   else if(n<0)
   cout<<-1;
   else
   {
       cout<<0;
   }
   
}