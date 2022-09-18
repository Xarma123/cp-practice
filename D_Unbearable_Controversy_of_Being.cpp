#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, m;
    cin >> n >> m;
    vector<lol> g[n + 1];
    bool ad[n + 1][n + 1];
    memset(ad, false, sizeof(ad));
    while (m--)
    {
        lol a, b;
        cin >> a >> b;
        g[a].push_back(b);
        ad[a][b] = true;
    }
    lol ans = 0;
    for (lol i = 1; i <= n; i++)
    {
        for (lol j = 1; j <= n; j++)
        {
            if (i != j)
            {
                lol c = 0;
                for (auto e : g[i])
                {
                    if (e != j && e != i && ad[e][j])
                    {
                        c++;
                    }
                }
                ans += c * 1ll * (c - 1) / 2;
            }
        }
    }
    cout << ans;

    return 0;
}