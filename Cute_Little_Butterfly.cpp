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
    lol cae = 1;
    while (t--)
    {
        lol n, e;
        cin >> n >> e;
        lol nec[501][501];
        for (lol i = 0; i <= 500; i++)
        {
            for (lol j = 0; j <= 500; j++)
            {
                nec[i][j] = 0;
            }
        }

        while (n--)
        {
            lol x, y, c;
            cin >> x >> y >> c;
            nec[x][y] += c;
        }
        lol ans = LONG_LONG_MIN;
        lol dp[501][501];
        lol dpl[501][501]; 
        for (lol i = 0; i <= 500; i++)
        {
            dp[i][j] = nec[i][500];
            if (i > 0)
                dp[i][500] += dp[i - 1][500];
            ans = max(ans, dp[i][500]);
        }
        for (lol j = 499; j >= 0; j--)
        {
            for (lol i = 0; i <= 500; i++)
            {
                dp[i][j] = nec[i][j];
                if (i > 0)
                {
                    dp[i][j] += max(dp[i - 1][j], dp[i][j + 1]);
                }
                else
                    dp[i][j] += dp[i][j + 1];
                ans = max(ans, dp[i][j]);
            }
        }
        cout << "Case #" << cae << ": " << ans << endl;
        cae++;
    }

    return 0;
}