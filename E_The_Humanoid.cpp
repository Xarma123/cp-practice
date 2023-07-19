#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        lol n, h;
        cin >> n >> h;
        lol a[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        sort(a, a + n);
        lol dp[n + 1][3][2];
        for (lol i = 0; i < 3; i++)
        {
            for (lol j = 0; j < 2; j++)
            {
                dp[0][i][j] = powl(2, i) * 1ll * powl(3, j) * 1ll * h;
            }
        }
        lol l = 0;
        for (lol i = 0; i < n; i++)
        {
            for (lol j = 0; j < 3; j++)
            {
                for (lol k = 0; k < 2; k++)
                {
                    lol hmax = -1;
                    for (lol j1 = 0; j1 <= j; j1++)
                    {
                        for (lol k1 = 0; k1 <= k; k1++)
                        {
                            if (dp[i][j1][k1] != -1)
                            {
                                hmax = max(hmax, dp[i][j1][k1] * 1ll * (long long)powl(2, j - j1) * 1ll * (long long)powl(3, k - k1));
                            }
                        }
                    }
                    if (hmax > a[i])
                    {
                        dp[i + 1][j][k] = hmax + (a[i] / 2);
                        l = i + 1;
                    }
                    else
                        dp[i + 1][j][k] = -1;
                }
            }
        }
        cout << l << '\n';
    }
}