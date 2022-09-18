#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        lol n, k;
        cin >> n >> k;
        lol a[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        sort(a, a + n);
        lol p = n - k - 1;
        if (p > -1)
        {
            while (a[p] == a[n - k])
            {
                p--;
                if (p == -1)
                    break;
            }
        }
        lol c = n - k - p;
        p = n - k + 1;
        if (p < n)
        {
            while (a[p] == a[n - k])
            {
                p++;
                if (p == n)
                    break;
            }
        }

        lol r = p - (n - k);
        c += r - 1;
        // cCr
        lol dp[c + 1][r + 1];
        for (lol i = 0; i <= c; i++)
        {
            for (lol j = 0; j <= r; j++)
            {
                if (j > i)
                    break;
                else if (i == j)
                    dp[i][j] = 1;
                else if (i == j - 1)
                    dp[i][j] = i;
                else if (j == 1)
                    dp[i][j] = i;
                else if (j == 0)
                    dp[i][j] = 1;
                else
                {
                    dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - 1]) % (1000000007);
                }
            }
        }
        cout << dp[c][r] << endl;
    }

    return 0;
}