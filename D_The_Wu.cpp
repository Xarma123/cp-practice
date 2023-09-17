#include <bits/stdc++.h>
using namespace std;
#define lol long long
lol ss(string a)
{
    lol v = 0;
    lol c = 1;
    for (lol i = 0; i < a.size(); i++)
    {
        v += (a[i] - '0') * 1ll * c;
        c = c * 2ll;
    }
    return v;
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, m, q;
    cin >> n >> m >> q;
    lol w[n];
    for (lol i = 0; i < n; i++)
    {
        cin >> w[i];
    }
    lol count[(1ll << (n))];
    memset(count, 0, sizeof(count));
    for (lol i = 0; i < m; i++)
    {
        string s;
        cin >> s;
        count[ss(s)]++;
    }
    lol dp[(1ll << (n))][101];
    memset(dp, 0, sizeof(dp));
    for (lol i = 0; i < (1ll << n); i++)
    {
        for (lol j = 0; j < (1ll << n); j++)
        {
            lol val = 0;
            for (lol b = 0; b < n; b++)
            {
                if ((i & (1ll << b)) == (j & (1ll << b)))
                {
                    val += w[b];
                }
            }
            if (val <= 100)
                dp[i][val] += count[j];
        }
        for (lol j = 1; j <= 100; j++)
        {
            dp[i][j] += dp[i][j - 1];
        }
    }
    while (q--)
    {
        string s;
        cin >> s;
        lol k;
        cin >> k;
        cout << dp[ss(s)][k] << '\n';
    }
}