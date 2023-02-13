#include <bits/stdc++.h>
#define lol long long
using namespace std;
lol mp[11][100001];
lol b[11][100001];
lol dp[100001];
lol n, m;
void dfs(lol c)
{
    lol nx = -1;
    for (lol i = 0; i < m && nx != -2; i++)
    {
        if (mp[i][c] != -1)
        {
            if (nx == -1)
            {
                nx = mp[i][c];
            }
            else if (nx != mp[i][c])
                nx = -2;
        }
        else
            nx = -2;
    }
    if (nx != -2)
    {
        if (dp[nx] == -1)
            dfs(nx);
        dp[c] = 1 + dp[nx];
    }
    else
        dp[c] = 1;
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    memset(mp, -1, sizeof(mp));
    for (lol i = 0; i < m; i++)
    {
        for (lol j = 0; j < n; j++)
        {
            lol q;
            cin >> q;
            b[i][j] = q;
            if (j)
            {
                mp[i][b[i][j - 1]] = q;
            }
        }
    }
    memset(dp, -1, sizeof(dp));
    lol ans = 0;
    for (lol i = 1; i <= n; i++)
    {
        if (dp[i] == -1)
        {
            dfs(i);
        }
        ans += dp[i];
    }
    cout << ans << '\n';

    return 0;
}