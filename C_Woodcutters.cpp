#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n;
    cin >> n;
    pair<lol, lol> tree[n];
    for (lol i = 0; i < n; i++)
    {
        cin >> tree[i].first >> tree[i].second;
    }
    lol dp[n][3];
    dp[0][0] = 0;
    dp[0][1] = 1;
    dp[0][2] = 1;
    lol i = 0;
    if (i + 1 < n)
    {
        if (tree[i + 1].first > tree[i].first + tree[i].second)
            dp[0][2] = 1;
        else
            dp[0][2] = LONG_LONG_MIN;
    }
    lol ans = 1;
    for (i = 1; i < n; i++)
    {
        dp[i][0] = ans;
        dp[i][1] = LONG_LONG_MIN;
        if (tree[i].first - tree[i].second > tree[i - 1].first + tree[i - 1].second)
            dp[i][1] = max(dp[i][1], 1 + dp[i - 1][2]);
        if (tree[i].first - tree[i].second > tree[i - 1].first)
            dp[i][1] = max(dp[i][1], 1 + max(dp[i - 1][0], dp[i - 1][1]));
        dp[i][2] = ans + 1;
        if (i + 1 < n)
        {
            if (tree[i + 1].first > tree[i].first + tree[i].second)
                dp[i][2] = 1 + ans;
            else
                dp[i][2] = LONG_LONG_MIN;
        }
        ans = max(ans, max(dp[i][0], max(dp[i][1], dp[i][2])));
    }
    cout << ans;

    return 0;
}