#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol mod = 998244353;
    lol n, m;
    cin >> n >> m;
    string a, b;
    cin >> a >> b;
    lol ans = 0;
    lol dp[b.size()];
    for (lol i = 0; i < b.size(); i++)
    {
        dp[i] = 0;
        if (i)
            dp[i] = (dp[i] + dp[i - 1]) % mod;
        if (b[i] == '1')
            dp[i]++;
        dp[i] %= mod;
    }
    lol v = 1;
    for (lol i = a.size() - 1; i >= 0; i--)
    {
        lol j = b.size() - (a.size() - i);
        if (j < b.size() && j >= 0)
        {
            if (a[i] == '1')
            {
                ans = (ans + (dp[j] * 1ll * v) % mod) % mod;
            }
        }
        v = (v * 2ll) % mod;
    }
    cout << ans;

    return 0;
}