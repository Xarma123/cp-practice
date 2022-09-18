#include <bits/stdc++.h>
#define lol long long
using namespace std;

int main()
{
    lol n;
    cin >> n;
    lol a[n];
    lol b[n];
    lol p[n + 1];
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
        p[a[i]] = i;
    }
    for (lol i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    lol r[n + 1] = {0};
    for (lol i = 0; i < n; i++)
    {
        if (i <= p[b[i]])
        {
            r[p[b[i]] - i]++;
        }
        else
        {
            r[p[b[i]] + n - i]++;
        }
    }
    lol ans = INT_MIN;
    for (lol i = 0; i < n + 1; i++)
    {
        ans = max(ans, r[i]);
    } 

    cout<<ans;

    return 0;
}