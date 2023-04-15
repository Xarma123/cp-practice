#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n;
    cin >> n;
    lol v[n];
    lol su = 0;
    for (lol i = 0; i < n; i++)
    {
        cin >> v[i];
        su += v[i];
    }
    lol time[n + 1];
    time[0] = LONG_LONG_MAX;
    lol mn = 0;
    lol q = 0;
    for (lol i = 1; i <= n; i++)
    {
        lol t = ceill(su / (long double)i);
        t = max(t, mn);
        time[i] = t;
        q += v[i - 1];
        t = ceill(q / (long double)i);
        mn = max(mn, t);
    }
    cin >> q;
    while (q--)
    {
        lol t;
        cin >> t;
        lol s = 0, e = n + 1;
        while (s != e - 1)
        {
            lol m = (s + e) / 2;
            if (m == n + 1)
                e = m;
            else if (time[m] <= t)
                e = m;
            else
                s = m;
        }
        if (e == n + 1)
            cout << -1 << '\n';
        else
            cout << e << '\n';
    }

    return 0;
}