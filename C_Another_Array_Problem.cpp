#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol t;
    cin >> t;
    while (t--)
    {
        lol n;
        cin >> n;
        lol a[n];
        set<pair<lol, lol>> x;
        lol c[n + 1];
        c[0] = 0;
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
            c[i + 1] = c[i] + a[i];
            x.insert({a[i], i});
        }
        while (!x.empty())
        {
            lol v = (*x.begin()).first;
            lol i = (*x.begin()).second;
            lol v2 = (*x.rbegin()).first;
            lol j = (*x.rbegin()).second;
            if (abs(v2 - v) * 1ll * abs(i - j + 1) >= c[max(j, i) + 1] - c[min(i, j)])
            {
                for (lol k = min(i, j); k <= max(i, j); k++)
                {
                    x.erase({a[k], k});
                    x.insert({abs(v2 - v), k});
                    a[k] = abs(v2 - v);
                }
            }
            else
            {
                x.erase({a[j], j});
            }
        }
        lol ans = 0;
        for (lol i = 0; i < n; i++)
        {
            ans += a[i];
        }
        cout << ans << endl;
    }

    return 0;
}