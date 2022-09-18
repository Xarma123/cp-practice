#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, k;
    cin >> n >> k;
    lol dp[n + 1][k + 1];
    map<lol, vector<lol>> mp;
    for (lol i = 1; i <= n; i++)
    {
        for (lol j = i; j <= n; j += i)
        {
            mp[j].push_back(i);
        }
    }

    lol m = 1e9 + 7;
    for (lol j = 0; j <= k; j++)
    {
        for (lol i = 0; i <= n; i++)
        {
            if (i == 0)
                dp[i][j] = 0;
            else if (j == 0)
                dp[i][j] = 0;
            else if (j == 1)
            {
                dp[i][j] = 1;
            }
            else
            {
                dp[i][j] = 0;
                for (auto e : mp[i])
                {
                    dp[i][j] = (dp[i][j] + dp[e][j - 1]) % m;
                }
            }
        }
    }
    lol ans = 0;
    for (lol i = 0; i <= n; i++)
    {
        ans = (ans + dp[i][k]) % m;
    }

    cout << ans << endl;

    return 0;
}