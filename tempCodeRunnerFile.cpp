#include <bits/stdc++.h>
#define lol int
using namespace std;
map<lol, vector<pair<lol, lol>>> mp;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, m, t;
    cin >> n >> m >> t;
    map<lol, lol> ind;
    while (m--)
    {
        lol a, b, c;
        cin >> a >> b >> c;
        mp[a].push_back({b, c});
        ind[b]++;
    }
    queue<lol> bfs;
    lol dp[n + 1][n + 1];
    lol parent[n + 1][n + 1];
    for (lol i = 0; i <= n; i++)
    {
        for (lol j = 0; j <= n; j++)
        {
            dp[i][j] = 1e9 + 1;
            parent[i][j] = -1;
        }
    }

    for (lol i = 1; i <= n; i++)
    {
        if (ind[i] == 0)
        {
            bfs.push(i);
        }
    }
    dp[1][1] = 0;
    while (!bfs.empty())
    {
        lol top = bfs.front();
        bfs.pop();
        for (auto e : mp[top])
        {
            if (--ind[e.first] == 0)
                bfs.push(e.first);
            for (lol i = 1; i <= n; i++)
            {
                if (dp[top][i - 1] + e.second < dp[e.first][i])
                {
                    parent[e.first][i] = top;
                    dp[e.first][i] = dp[top][i - 1] + e.second;
                }
            }
        }
    }

    for (lol i = n; i >= 0; i--)
    {
        if (dp[n][i] <= t)
        {

            cout << i << endl;
            lol c = n;
            stack<lol> x;

            while (c != 1)
            {
                x.push(c);
                c = parent[c][i];
                i--;
            }
            x.push(c);
            while (!x.empty())
            {
                cout << x.top() << " ";
                x.pop();
            }
            break;
        }
    }

    return 0;
}