#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol n;
    cin >> n;
    lol a[n];
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    lol c[n + 1];
    c[n] = 0;
    set<lol> s;
    for (lol i = n - 1; i >= 0; i--)
    {
        if (!s.count(a[i]))
        {
            c[i] = c[i + 1] + 1;
            s.insert(a[i]);
        }
        else
            c[i] = c[i + 1];
    }
    lol ans = 0;
    s.clear();
    for (lol i = 0; i < n; i++)
    {
        if (!s.count(a[i]))
        {
            ans += c[i + 1];
            s.insert(a[i]);
        }
    }
    cout << ans;

    return 0;
}