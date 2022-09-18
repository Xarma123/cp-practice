#include<bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{      freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    lol n; cin>>n;
    string ar ; cin>>ar;
     lol a[n];
     for (lol i = 0; i < n; i++)
     {
       a[i]=i;
     } 
     for (lol i = 1; i <n; i=i+2)
     {   if(i!=n-1)
         swap(a[i],a[i+1]);
     } 
     for (lol i = 1; i < n; i=i+2)
     { 
        if(ar[a[i]]==ar[a[i-1]] )
         cout<<a[i]+1<<" "<<a[i-1]+1<<endl;
         else
         { if(ar[a[i]]=='L')
           {
             cout<<a[i]+1<<" "<<a[i-1]+1<<endl;
           }
           else
           {
               cout<<a[i-1]+1<<" "<<a[i]+1<<endl;
           }

         }




     }
     
     
     
     

return 0;
}