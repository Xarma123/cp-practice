#include <iostream>
#include <algorithm>

using namespace std;
int main()
{
   string a; string b;
   cin>>a>>b;
   for (lol i = 0; i < a.size(); i++)
   {
          if(a[i]==b[i])
          {
              a[i]='0';
          }
          else
          {
              a[i]='1';
          } 
          
   } 
   cout<<a;
     



}
