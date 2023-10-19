#include <bits/stdc++.h>
using namespace std;
#define lol long long
lol first(lol a)
{
    for (lol i = 63; i >= 0; i--)
    {
        if ((a & (1ll << i)))
            return i;
    }
    return 0;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, m;
    cin >> n >> m;
    bool ed[n][n];
    memset(ed, false, sizeof(ed));
    while (m--)
    {
        lol a, b;
        cin >> a >> b;
        a--;
        b--;
        ed[a][b] = true;
        ed[b][a] = true;
    }
    lol dp[(1ll << n)][n];
    for (lol i = 0; i < (1ll << n); ++i)
    {
        for (lol j = 0; j < n; j++)
        {
            if (i == 0)
                dp[i][j] = 0;
            else if (!(i & (1 << j)))
                dp[i][j] = 0;
            else if (__builtin_popcount(i) == 1)
            {
                dp[i][j] = 1;
            }
            else if (first(i) == j)
            {
                dp[i][j] = 0;
            }
            else
            {
                dp[i][j] = 0;
                for (lol k = 0; k < n; k++)
                {
                    if (ed[k][j])
                    {
                        dp[i][j] += dp[(i ^ (1ll << j))][k];
                    }
                }
            }
           
        }
     
    }
    lol ans = 0;
    for (lol i = 0; i < (1ll << n); i++)
    {
        for (lol j = 0; j < n; j++)
        {
            if (__builtin_popcount(i) < 3)
                continue;
            if (ed[j][first(i)])
                ans += dp[i][j];
        }
    }
    cout << ans / 2ll;

    return 0;
}
