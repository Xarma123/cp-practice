#include <bits/stdc++.h>
#define lol long long
using namespace std;
struct trip
{
    lol o;
    lol n;
    lol w;
};

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol c;
    cin >> c;
    while (c--)
    {
        lol ox, nt;
        cin >> ox >> nt;
        lol n;
        cin >> n;
        trip a[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i].o >> a[i].n >> a[i].w;
        }
        lol dp[n + 1][nt + 1][ox + 1];
        for (lol i = 0; i <= n; i++)
        {
            for (lol j = 0; j <= nt; j++)
            {
                for (lol k = 0; k <= ox; k++)
                {
                    if (i == 0 && j == 0 && k == 0)
                    {
                        dp[i][j][k] = 0;
                    }
                    else if (i == 0)
                    {
                        dp[i][j][k] = INT_MAX;
                    }
                    else if (j == 0 && k == 0)
                    {
                        dp[i][j][k] = 0;
                    }
                    else
                    {
                        dp[i][j][k] = dp[i - 1][j][k];
                        lol o = a[i - 1].o;
                        lol n = a[i - 1].n;
                        dp[i][j][k] = min(dp[i - 1][max(j - n, 0 * 1ll)][max(k - o, 0 * 1ll)] + a[i - 1].w, dp[i][j][k]);
                    }
                }
            }
        }
        cout << dp[n][nt][ox] << endl;
    }

    return 0;
}