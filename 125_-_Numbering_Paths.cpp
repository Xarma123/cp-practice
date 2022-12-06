#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n;
    lol c = 0;
    while (cin >> n)
    {
        map<lol, vector<lol>> mp;
        lol mx = 0;
        for (lol i = 0; i < n; i++)
        {
            lol a, b;
            cin >> a >> b;

            mx = max(mx, a);
            mx = max(mx, b);
            mp[a].push_back(b);
        }
        lol dp[mx + 1][mx + 1];
        lol dis[mx + 1][mx + 1];
        for (lol i = 0; i <= mx; i++)
        {
            for (lol j = 0; j <= mx; j++)
            {
                dp[i][j] = 0;
                dis[i][j] = 1e9;
            }
        }

        for (auto e : mp)
        {
            for (auto s : e.second)
            {
                dp[e.first][s] = 1;
                dis[e.first][s] = -1;
            }
        }
        for (lol k = 0; k <= mx; k++)
        {
            for (lol i = 0; i <= mx; i++)
            {
                for (lol j = 0; j <= mx; j++)
                {
                    dp[i][j] += dp[i][k] * 1ll * dp[k][j];
                    if ((dis[i][j] > dis[i][k] + dis[k][j]) && dis[i][k] != 1e9 && dis[k][j] != 1e9)
                    {
                        dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
                    }
                }
            }
        }

        for (lol k = 0; k <= mx; k++)
        {
            for (lol i = 0; i <= mx; i++)
            {
                for (lol j = 0; j <= mx; j++)
                {

                    if (dis[i][j] > dis[i][k] + dis[k][j] && dis[i][k] != 1e9 && dis[k][j] != 1e9)
                    {
                        dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
                        dp[i][j] = -1;
                    }
                }
            }
        }
        cout << "matrix for city " << c << endl;
        c++;
        for (lol i = 0; i <= mx; i++)
        {
            for (lol j = 0; j <= mx; j++)
            {
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}