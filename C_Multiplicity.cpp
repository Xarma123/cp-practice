#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol m = 1e9 + 7;
    lol n;
    cin >> n;
    lol a[n];
    vector<lol> dp(n + 1, 0);
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    dp[0] = 1;

    for (lol i = 0; i < n; i++)
    {

        lol q = a[i];
        vector<lol> x;
        for (lol j = 1; j * j <= q && j <= n; j++)
        {
            if (q % j == 0)
            {
                x.push_back(j);
                lol j2 = q / j;
                if (j2 != j && j2 <= n)
                    x.push_back(j2);
            }
        }
        sort(x.begin(), x.end(),greater<lol>());
        for (lol i = 0; i < x.size(); i++)
        {
            dp[x[i]] = (dp[x[i]] + dp[x[i] - 1]) % m;
        }
    }
    lol ans = 0;
    for (lol i = 0; i < n; i++)
    {
        ans = (ans + dp[i + 1]) % m;
    }
    cout << ans << endl;

    return 0;
}