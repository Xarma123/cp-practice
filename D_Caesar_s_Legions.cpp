#include <bits/stdc++.h>
#define lol long long
using namespace std;

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n1, n2, k1, k2;
    cin >> n1 >> n2 >> k1 >> k2;

    lol dp[n1 + 1][n2 + 1][k1 + 1][k2 + 1];
    lol m = 1e8;
    for (lol f = 0; f <= n1; f++)
    {
        for (lol h = 0; h <= n2; h++)
        {
            for (lol kf = 0; kf <= k1; kf++)
            {
                for (lol kh = 0; kh <= k2; kh++)
                {
                    if (f + h == 0)
                        dp[f][h][kf][kh] = 1;
                    else
                    {
                        lol ans = 0;
                        if (kf > 0 && f > 0)
                            ans = (ans + dp[f - 1][h][kf - 1][k2]) % m;
                        if (kh > 0 && h > 0)
                            ans = (ans + dp[f][h - 1][k1][kh - 1]) % m;
                        dp[f][h][kf][kh] = ans;
                    }
                }
            }
        }
    }
    cout << dp[n1][n2][k1][k2] << endl;

    return 0;
}