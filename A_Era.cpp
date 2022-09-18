#include<bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{ 
 lol t; 
 cin>>t;
 while (t--)
 {
     lol n ;
      cin>>n;
     lol ans=0;
     for (lol i = 0; i < n; i++)
     { 
         lol t; cin>>t;
         if(t>i+1+ans)
         {
           ans+= t-i-1-ans;

         }
        
     } 
     cout<<ans<<endl;
     
 }
 

return 0;
}