#include <iostream>
#include <stack>
using namespace std;
int main()
{ lol n ; lol a[n];
for (lol i = 0; i < n; i++)
{
     cin>>a[i];
} 
lol mx=0,mxi;
stack<lol> ab;
for (lol i = 0; i < n; i++)
{
     if(a[i]>mx)
     {
        ab.push(i); 
        mxi=i; 
        mx=a[i];
     } 
     else
     {
         lol k = i-1;
         while(k>=mxi)
         {  if(a[i]<a[k])
              ab.push(k)  ;
              k--;  
         }
     }
    
}


  
}
