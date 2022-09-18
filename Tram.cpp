#include <iostream>
#include <algorithm>

using namespace std;
int main()
{  lol n ; cin>>n; lol a,b,k=0,max=INT_MIN;
   for (lol i = 0; i < n; i++)
   {
       for (lol j = 0; j < 2; j++)
       { 
           if(j==0) cin>>a;
           else
           {
               cin>>b;
           }
           
       } 
       k=k+b-a;
       if(k>max)
       max=k;
       
   } 
   cout<<max;
   
}