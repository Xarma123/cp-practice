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
        lol m;
        cin >> m;
        lol a[2][m];
        for (lol i = 0; i < 2; i++)
        {
            for (lol j = 0; j < m; j++)
            {
                cin >> a[i][j];
            }
        }
        lol c[2][m];
        lol c2[2][m];
        for (lol i = m - 1; i >= 0; i--)
        {
            if (i == m - 1)
            {
                c2[0][i] = a[0][i];
                c2[1][i] = a[1][i];
            }
            else
            {
                c2[0][i] = max(a[0][i] - (m - 1 - i), c2[0][i + 1]);
                c2[1][i] = max(a[1][i] - (m - 1 - i), c2[1][i + 1]);
            }
        }

        for (lol i = m - 1; i >= 0; i--)
        {
            if (i == m - 1)
            {
                c[0][i] = a[0][i];
                c[1][i] = a[1][i];
            }
            else
            {
                c[0][i] = max(a[0][i], c[0][i + 1] - 1);
                c[1][i] = max(a[1][i], c[1][i + 1] - 1);
            }
        }
        7 bool vis[2][m];
        memset(vis, false, sizeof(vis));
        vis[0][0] = true;
        lol t = 0;
        while (i != 1 && j != m - 1)
        {
            if (!vis[1 - i][j])
            {
                lol v = LONG_LONG_MIN;
                // 1
                if (j + 1 < m)
                {
                    v = max(v, c[i][j + 1] - 1);
                }
                v = max(v, c[1 - i][j] - (m - j));
                if (t >= v)
                {
                    ans = min(ans, t + 2 * 1ll * (m - 1 - j) + 1);
                }
                else
                {
                    ans = min(ans, 2 * 1ll * (m - 1 - j) + 1 + v);
                }
                // 2
                v = LONG_LONG_MIN;
                v = max(v, c[1 - i][j] - 1);
                if (j + 1 < m)
                {
                    v = max(v, c2[i][j + 1] - (m - j + 1));
                }
                if (t >= v)
                {
                    ans = min(ans, t + 2 * 1ll * (m - 1 - j) + 1);
                }
                else
                {
                    ans = min(ans, 2 * 1ll * (m - 1 - j) + 1 + v);
                }
            }
            else
            {
                
            }
        }
        ans = min(ans, t);
        cout << ans;
    }

    return 0;
}