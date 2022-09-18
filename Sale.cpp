#include <bits/stdc++.h>
using namespace std;
int main()
{
    lol n , m ; cin>>n>>m; lol a[n];
    for (lol i = 0; i < n; i++)
    {
        cin>>a[i];
    } 
    sort(a,a+n); lol sum=0;
    for (lol i = 0; i < m; i++)
    {
        if(a[i]<0) 
        sum+=a[i];
        else
        {
            break;
        }
        
    } 
    cout<<abs(sum);
    
    
}