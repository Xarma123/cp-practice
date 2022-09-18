#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long d;
    cin >> d;
    long long m;
    cin >> m;
    long long n;
    cin >> n;
    long long a[n+1];a[0]=0;
    for (long long i = 1; i < n+1; i++)
    {
        cin >> a[i];
    }
    long long ls = 0, cs = 0,ans=0;

    while (cs<n+1)
    {
        ls=cs;
    
    
    while (cs <= n && a[cs+1 ] - a[ls] <= m)
    { 
        cs++;
        if(cs==n) 
        {
            ans++; break;
        }

    } 
    if(cs==n)
    {
      cout<<ans; 
      break;
    }
    else if(cs==ls)
    {
        cout<<-1; 
        break;
    }
    else
    {
        ans++;
    }
    }
    return 0;
}