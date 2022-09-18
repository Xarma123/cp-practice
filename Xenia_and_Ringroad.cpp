#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long lol n ; cin>>n;
    long long lol m ; cin>>m;
    long long lol a[m];long long  lol t = 0 ; cin>>a[0] ; t+=a[0]-1;
    for (long long lol i = 1; i < m; i++)
    {
       cin>>a[i]; 
       if(a[i]==a[i-1])
         continue;
         if(a[i-1]<a[i])
          t+=a[i]-a[i-1];
         else
         { 
             t+=n-a[i-1] +a[i];
             
             
         }
         
    } 
   
    
    cout<<t;

}