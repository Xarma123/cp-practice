#include <bits/stdc++.h>
#define lol long long
using namespace std;

lol rd[102];
lol dp[101][101][101];
lol solve(vector<lol> g, lol i, lol j, lol ex)
{
    if (i > j)
        return 0;
    if (dp[i][j][ex] != -1)
        return dp[i][j][ex];

    lol ans = LONG_LONG_MIN;
    ans = max(ans, rd[g[i] + ex] + solve(g, i + 1, j, 0));
    for (lol k = i + 2; k <= j; k += 2)
    {
        ans = max(ans, solve(g, i + 1, k - 1, 0) + solve(g, k, j, ex + g[i]));
    }
    dp[i][j][ex] = ans;
    return ans;
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n;
    cin >> n;
    string s;
    cin >> s;
    lol a[n + 1];
    for (lol i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    rd[0] = 0;
    for (lol i = 1; i <= n; i++)
    {
        rd[i] = LONG_LONG_MIN;
        for (lol j = i; j >= 1; j--)
        {
            rd[i] = max(rd[i], a[i - j + 1] + rd[j - 1]);
        }
    }
    memset(dp, -1, sizeof(dp));
    vector<lol> g;
    for (lol i = 0; i < n; i++)
    {
        lol j = i + 1;
        if (j < n)
        {
            while (s[i] == s[j])
            {
                j++;
                if (j == n)
                    break;
            }
        }
        g.push_back(j - i);
        i = j - 1;
    }

    cout << solve(g, 0, g.size() - 1, 0);
    return 0;
}