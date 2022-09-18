#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol n;
    cin >> n;
    lol m;
    cin >> m;
    lol a[n];
    lol s = 0;
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
        s += a[i]; 
    }
    sort(a, a + n); 
    if(m+s<=a[n-1]*n)
    {
        cout<<a[n-1]<<" "<<a[n-1]+m;
    }
    else
    {
        lol e = m+s-a[n-1]*n;
        cout<<e/n+((e%n)>0)+a[n-1]<<" "<<a[n-1]+m;
    }

    return 0;
}