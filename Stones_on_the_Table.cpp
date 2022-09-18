#include<bits/stdc++.h>
using namespace std;
int main()
{
    lol n ; cin>>n;
    string a; cin>>a; lol ans=0;
    for (lol i = 0; i <n-1; i++)
    {
         if (a[i]==a[i+1])
         {  
             ans++;
             
         }
         
    } 
    cout<<ans;
    

}