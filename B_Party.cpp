#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol t;
    cin >> t;
    while (t--)
    {
        lol n, m;
        cin >> n >> m;
        lol a[n + 1];
        for (lol i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        map<lol, lol> f;
        map<lol, vector<lol>> mp;
        for (lol i = 0; i < m; i++)
        {

            lol x, y;
            cin >> x >> y;
            f[x]++;
            f[y]++;
            mp[x].push_back(y);
            mp[y].push_back(x);
        }
        if ((m % 2) == 0)
        {
            cout << 0 << '\n';
            continue;
        }

        lol ans = LONG_LONG_MAX;
        for (lol i = 1; i <= n; i++)
        {
            if (f[i] % 2 != 0)
            {
                ans = min(ans, a[i]);
            }
            else
            {
                lol c = LONG_LONG_MAX;
                for (auto e : mp[i])
                {
                    if (f[e] % 2 == 0)
                    {
                        c = min(c, a[e]);
                    }
                }
                if (c != LONG_LONG_MAX)
                {
                    ans = min(ans, c + a[i]);
                }
            }
        }
        cout << ans << '\n';
    }
}