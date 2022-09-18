#include <bits/stdc++.h>
#define lol long long
using namespace std;
string n;
lol a, b, k;
lol dp[11][2][90][90];
lol solve(lol i, bool l, lol sum, lol d_sum)
{
    if (i == n.size())
    {
        if (sum == 0 && d_sum == 0)
            return 1;
        return 0;
    }
    if (dp[i][l][sum][d_sum] != -1)
        return dp[i][l][sum][d_sum];
    lol till = (l ? n[i] - '0' : 9);
    lol ans = 0;
    for (lol j = 0; j <= till; j++)
    {
        ans += solve(i + 1, (l && (j == till)), (sum * 1ll * 10 + j) % k, (d_sum + j) % k);
    }
    return dp[i][l][sum][d_sum] = ans;
}
lol solve(lol _n)
{
    n = to_string(_n);
    if (k > 90)
        return 0;
    memset(dp, -1, sizeof(dp));
    return solve(0, true, 0, 0);
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol t;
    cin >> t;
    lol c = 1;
    while (c <= t)
    {
        cin >> a >> b >> k;
        cout << "Case " << c << ": ";
        c++;
        cout << solve(b) - solve(a - 1) << endl;
    }

    return 0;
}