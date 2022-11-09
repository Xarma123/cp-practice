#include <bits/stdc++.h>
#define lol long long
using namespace std;
lol m = 1e8;
lol n1_, n2_, k1, k2;
lol dp[101][101][11][11];
lol solve(lol n1, lol n2, lol f, lol h)
{
    if (dp[n1][n2][f][h] != -1)
        return dp[n1][n2][f][h];

    if (n1 + n2 == 0)
        return 1;
    if (n1 > 0 && n2 == 0)
    {
        if (f + n1 <= k1)
            return 1;
        else
            return 0;
    }
    if (n2 > 0 && n1 == 0)
    {
        if (h + n2 <= k2)
            return 1;
        else
            return 0;
    }
    lol ans = 0;
    if (f + 1 <= k1)
    {
        ans += solve(n1 - 1, n2, f + 1, 0);
        ans %= m;
    }
    if (h + 1 <= k2)
    {
        ans += solve(n1, n2 - 1, 0, h + 1);
        ans %= m;
    }
    return dp[n1][n2][f][h] = ans;
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n1_ >> n2_ >> k1 >> k2;
    memset(dp, -1, sizeof(dp));
    cout << solve(n1_, n2_, 0ll, 0ll);

    return 0;
}