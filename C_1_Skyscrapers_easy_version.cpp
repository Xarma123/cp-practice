#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n;
    cin >> n;
    lol a[n];
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
    }
 
    lol ans = 0;
    lol v = LONG_LONG_MIN;
    for (lol i = 0; i < n; i++)
    {
        lol mn = a[i];
        lol c = a[i];
        for (lol j = i - 1; j >= 0; j--)
        {
            mn = min(mn, a[j]);
            c += mn;
        }
        mn = a[i];
        for (lol j = i + 1; j < n; j++)
        {
            mn = min(mn, a[j]);
            c += mn;
        }
        if (c > v)
        {
            ans = i;
            v = c;
        }
    }
    lol b[n];
    lol mn = a[ans];
    b[ans] = a[ans];
    for (lol j = ans - 1; j >= 0; j--)
    {
        mn = min(mn, a[j]);
        b[j] = mn;
    }
    mn = a[ans];
    for (lol j = ans + 1; j < n; j++)
    {
        mn = min(mn, a[j]);
        b[j] = mn;
    }
    for (lol i = 0; i < n; i++)
    {
        cout << b[i] << " ";
    }
}