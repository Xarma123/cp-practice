#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol H, W;
    cin >> H >> W;
    string a[H];
    for (lol i = 0; i < H; i++)
    {
        cin >> a[i];
    }
    lol m = 1e9 + 7;
    lol dp[H][W];
    for (lol i = 0; i < H; i++)
    {
        for (lol j = 0; j < W; j++)
        {
            if (i == 0 && j == 0)
                dp[i][j] = 1;
            else if (a[i][j] == '#')
            {
                dp[i][j] = 0;
            }
            else
            {
                dp[i][j] = 0;
                if (j - 1 >= 0)
                    dp[i][j] += dp[i][j - 1];
                dp[i][j] %= m;
                if (i - 1 >= 0)
                    dp[i][j] += dp[i - 1][j];
                dp[i][j] %= m;
            }
        }
    }
    cout << dp[H - 1][W - 1];

    return 0;
}