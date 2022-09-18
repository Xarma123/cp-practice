#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
   lol n;cin>>n;
   double ans=0; double temp;
   for (lol i = 0; i < n; i++)
   {  cin>>temp;
      ans+=temp;
       
   } 
   cout<<(ans/n);
   


}