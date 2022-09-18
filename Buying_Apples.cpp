#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol t;
    cin >> t;
    while (t--)
    {
        lol n, k;
        cin >> n >> k;
        lol p[k];
        for (lol i = 0; i < k; i++)
        {
            cin >> p[i];
        }
        pair<lol, lol> dp[k + 1][k + 1];
        for (lol i = 0; i <= k; i++)
        {
            for (lol j = 0; j <= k; j++)
            {
                if (i == 0)
                    dp[i][j] = {0, 0};
                else if (j == 0)
                    dp[i][j] = {-1, -1};
                else
                {
                    dp[i][j] = dp[i][j - 1];
                    if (p[j - 1] != -1)
                    {
                        if (i - j >= 0)
                        {
                            if (dp[i - j][j].first != -1)
                            {
                                if (dp[i - j][j].second + 1 <= n)
                                {
                                    if (dp[i][j].first == -1)
                                    {
                                        dp[i][j] = {dp[i - j][j].first + p[j - 1], dp[i - j][j].second + 1};
                                    }
                                    else
                                    {
                                        if (dp[i - j][j].first + p[j - 1] < dp[i][j].first)
                                        {
                                            dp[i][j] = {dp[i - j][j].first + p[j - 1], dp[i - j][j].second + 1};
                                        }
                                        else if (dp[i - j][j].first + p[j - 1] == dp[i][j].first)
                                        {
                                            if (dp[i - j][j].second + 1 <= dp[i][j].second)
                                                dp[i][j] = {dp[i - j][j].first + p[j - 1], dp[i - j][j].second + 1};
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        cout << dp[k][k].first << endl;
    }

    return 0;
}