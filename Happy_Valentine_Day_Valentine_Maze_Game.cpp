#include <bits/stdc++.h>
using namespace std;
#define lol long long
lol n, m;
void solve(lol c, vector<lol> d[], vector<vector<lol>> &w, string a[])
{

    lol dis[n][m];
    for (lol i = 0; i < n; i++)
    {
        for (lol j = 0; j < m; j++)
        {
            dis[i][j] = LONG_LONG_MAX;
        }
    }
    lol i = w[c][0], j = w[c][1];
    queue<pair<lol, lol>> q;
    q.push({i, j});
    dis[i][j] = 0;

    while (!q.empty())
    {

        pair<lol, lol> top = q.front();

        q.pop();
        lol dx[4] = {-1, 0, 0, 1};
        lol dy[4] = {0, 1, -1, 0};
        for (int k = 0; k < 4; k++)
        {
            lol x = top.first + dx[k];
            lol y = top.second + dy[k];
            if (x >= 0 && x < n && y >= 0 && y < m && a[x][y] != '#')
            {
                if (dis[top.first][top.second] + 1 < dis[x][y])
                {
                    dis[x][y] = dis[top.first][top.second] + 1;
                    q.push({x, y});
                }
            }
        }
    }
    for (lol i = 0; i < w.size(); i++)
    {
        d[c][i] = dis[w[i][0]][w[i][1]];
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol t;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        string a[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        vector<vector<lol>> w;
        lol si, sj, ei, ej;
        for (lol i = 0; i < n; i++)
        {
            for (lol j = 0; j < m; j++)
            {
                if (a[i][j] == 'C')
                    w.push_back({i, j});
                else if (a[i][j] == 'T')
                    si = i, sj = j;
                else if (a[i][j] == 'W')
                    ei = i, ej = j;
            }
        }

        w.insert(w.begin(), {si, sj});
        w.push_back({ei, ej});
        vector<lol> d[w.size()];
        for (lol i = 0; i < w.size(); i++)
        {
            d[i].resize(w.size());
        }
        for (lol i = 0; i < w.size(); i++)
        {
            solve(i, d, w, a);
        }
        lol k = w.size();

        lol dp[(1ll << k)][k];
        for (lol i = 0; i < (1ll << k); i++)
        {
            for (lol j = 0; j < k; j++)
            {
                if (__builtin_popcount(i) == 0)
                {
                    dp[i][j] = LONG_LONG_MAX;
                }
                else if (__builtin_popcount(i) == 1)
                {
                    if (j == 0 && (i % 2 != 0))
                        dp[i][j] = 0;
                    else
                        dp[i][j] = LONG_LONG_MAX;
                }
                else if ((i & (1ll << j)) == 0)
                {
                    dp[i][j] = LONG_LONG_MAX;
                }
                else
                {
                    dp[i][j] = LONG_LONG_MAX;
                    for (lol q = 0; q < k; q++)
                    {
                        if (q != j && (i & (1ll << q)))
                        {
                            if (dp[(i ^ (1ll << j))][q] != LONG_LONG_MAX && d[q][j] != LONG_LONG_MAX)
                                dp[i][j] = min(dp[i][j], dp[(i ^ (1ll << j))][q] + d[q][j]);
                        }
                    }
                }
            }
        }
        if (dp[(1ll << k) - 1][k - 1] == LONG_LONG_MAX)
            cout << "Mission Failed!\n";
        else
            cout << dp[(1ll << k) - 1][k - 1] << '\n';
    }

    return 0;
}
