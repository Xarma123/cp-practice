#include <bits/stdc++.h>
using namespace std;
#define lol long long
lol dp[2][100005];
lol v[2][100005];
vector<lol> tree[100005];
void dfs(lol c, lol p)
{
    dp[0][c] = 0;
    dp[1][c] = 0;

    for (auto e : tree[c])
    {
        if (e != p)
        {
            dfs(e, c);
            dp[0][c] += max((long long)abs(v[0][c] - v[0][e]) + dp[0][e], (long long)abs(v[0][c] - v[1][e]) + dp[1][e]);
            dp[1][c] += max((long long)abs(v[1][c] - v[0][e]) + dp[0][e], (long long)abs(v[1][c] - v[1][e]) + dp[1][e]);
        }
    }
}
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
        for (lol i = 1; i <= n; i++)
        {
            cin >> v[0][i] >> v[1][i];
        }

        for (lol i = 0; i < n - 1; i++)
        {
            lol a, b;
            cin >> a >> b;
            tree[a].emplace_back(b);
            tree[b].emplace_back(a);
        }

        dfs(1, -1);
        cout << max(dp[0][1], dp[1][1]) << '\n';
        for (lol i = 0; i < n + 1; i++)
        {
            tree[i].clear();
        }
    }
}