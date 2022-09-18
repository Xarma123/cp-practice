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
        lol n, m;
        cin >> n >> m;
        string a[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        lol dp[n][m];
        lol wcl[m];
        for (lol j = 0; j < m; j++)
        {
            lol c = 0;
            for (lol i = 0; i < n; i++)
            {
                dp[i][j] = 0;
                if (i > 0)
                {
                    dp[i][j] += dp[i - 1][j] + c;
                }
                if (a[i][j] == 'W')
                    c++;
            }
            wcl[j] = c;
            c = 0;
            for (lol i = n - 1; i >= 0; i--)
            {
                dp[i][j] = 0;
                if (i != n - 1)
                {
                    dp[i][j] += dp[i + 1][j] + c;
                }
                if (a[i][j] == 'W')
                    c++;
            }
        }
        lol l[n][m];
        lol s = 0;
        for (lol j = 0; j < m; j++)
        {
            for (lol i = 0; i < n; i++)
            {
                if (j > 0)
                {
                    l[i][j] = dp[i][j - 1];
                    l[i][j] += l[i][j - 1];
                    l[i][j] += s;
                }
            }
            s += wcl[j];
        }
        lol r[n][m];
        s = 0;
        for (lol j = m - 1; j >= 0; j--)
        {
            for (lol i = 0; i < n; i++)
            {
                if (j != m - 1)
                {
                    r[i][j] = dp[i][j + 1];
                    r[i][j] += l[i][j + 1];
                    r[i][j] += s;
                }
            }
            s += wcl[j];
        }
        lol ans = LONG_LONG_MIN;
        lol le, re;
        for (lol i = 0; i < n; i++)
        {
            for (lol j = 0; j < m; j++)
            {
                if (ans <= dp[i][j] + l[i][j] + r[i][j])
                {
                    ans = dp[i][j] + l[i][j] + r[i][j];
                    le = i;
                    re = j;
                }
            }
        }
        cout << le + 1 << " " << re + 1 << endl;
    }

    return 0;
}