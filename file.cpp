#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n;
    cin >> n;
    lol a[n];
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    lol b[n];
    for (lol i = 0; i < n; i++)
    {
        b[i] = a[i] - i;
    }
    stack<lol> x;
    x.push(-1);
    lol pv[n];
    for (lol i = 0; i < n; i++)
    {
        while (x.top() != -1 && b[x.top()] >= b[i])
            x.pop();
        pv[i] = x.top();
        x.push(i);
    }
    lol ans = LONG_LONG_MIN;
    lol dp[n];
    for (lol i = 0; i < n; i++)
    {
        dp[i] = (i - pv[i]) * 1ll * a[i] - (((i - pv[i]) * 1ll * (i - pv[i] - 1)) / 2ll);
        if (pv[i] >= 0)
            dp[i] += dp[pv[i]];
        ans = max(ans, dp[i]);
    }
    cout << ans;
}