#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol R, G, B;
    cin >> R >> G >> B;
    lol r[R], g[G], b[B];
    for (lol i = 0; i < R; i++)
    {
        cin >> r[i];
    }
    for (lol i = 0; i < G; i++)
    {
        cin >> g[i];
    }
    for (lol i = 0; i < B; i++)
    {
        cin >> b[i];
    }
    sort(r, r + R);
    sort(g, g + G);
    sort(b, b + B);
    lol dp[R + 1][G + 1][B + 1];
    memset(dp, 0, sizeof(dp));
    for (lol i = 1; i <= G; i++)
    {
        for (lol j = 1; j <= B; j++)
        {
            dp[0][i][j] = max(dp[0][i - 1][j], dp[0][i][j - 1]);
            dp[0][i][j] = max(dp[0][i][j], dp[0][i - 1][j - 1] + g[G - i] * 1ll * b[B - j]);
        }
    }
    for (lol i = 1; i <= R; i++)
    {
        for (lol j = 1; j <= B; j++)
        {
            dp[i][0][j] = max(dp[i - 1][0][j], dp[i][0][j - 1]);
            dp[i][0][j] = max(dp[i][0][j], dp[i - 1][0][j - 1] + r[R - i] * 1ll * b[B - j]);
        }
    }
    for (lol i = 1; i <= R; i++)
    {
        for (lol j = 1; j <= G; j++)
        {
            dp[i][j][0] = max(dp[i - 1][j][0], dp[i][j - 1][0]);
            dp[i][j][0] = max(dp[i][j][0], dp[i - 1][j - 1][0] + r[R - i] * 1ll * g[G - j]);
        }
    }
    for (lol i = 1; i <= R; i++)
    {
        for (lol j = 1; j <= G; j++)
        {
            for (lol k = 1; k <= B; k++)
            {
                dp[i][j][k] = max(dp[i][j][k - 1], max(dp[i - 1][j][k], dp[i][j - 1][k]));
                dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j - 1][k] + r[R - i] * 1ll * g[G - j]);
                dp[i][j][k] = max(dp[i][j][k], dp[i][j - 1][k - 1] + b[B - k] * 1ll * g[G - j]);
                dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k - 1] + b[B - k] * 1ll * r[R - i]);
            }
        }
    }

    cout << dp[R][G][B];

    return 0;
}