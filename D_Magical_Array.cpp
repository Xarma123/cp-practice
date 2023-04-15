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
        lol n, m;
        cin >> n >> m;
        lol c[n][m];
        map<lol, lol> mp;
        for (lol i = 0; i < n; i++)
        {
            lol s = 0;
            for (lol j = 0; j < m; j++)
            {
                cin >> c[i][j];
                s += (c[i][j] * 1ll * (j + 1));
            }
            mp[s]++;
        }
        lol s;
        for (auto e : mp)
        {
            if (e.second > 1)
            {
                s = e.first;
            }
        }

        for (lol i = 0; i < n; i++)
        {
            lol s2 = 0;
            for (lol j = 0; j < m; j++)
            {
                s2 += (c[i][j] * 1ll * (j + 1));
            }
            if (s != s2)
            {
                cout << i + 1 << ' ' << s2 - s << '\n';

                break;
            }
        }
    }

    return 0;
}