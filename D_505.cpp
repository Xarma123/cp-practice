#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, m;
    cin >> n >> m;
    string a[n];
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    if (min(n, m) > 3)
    {
        cout << -1;
    }
    else
    {
        vector<string> b;
        if (n > m)
        {

            for (lol j = 0; j < m; j++)
            {
                string s = "";
                for (lol i = 0; i < n; i++)
                {
                    s += a[i][j];
                }
                b.push_back(s);
            }
            swap(m, n);
        }
        else
        {

            for (lol i = 0; i < n; i++)
            {
                b.push_back(a[i]);
            }
        }
        if (n == 1)
            cout << 0;
        else if (n == 2)
        {
            // s b s b
            lol c1 = 0;
            for (lol j = 0; j < m; j++)
            {
                lol v = b[0][j] - '0';
                v += b[1][j] - '0';
                if (j % 2 == 0)
                {
                    if (v == 1)
                    {
                        c1++;
                    }
                }
                else
                {
                    if (v != 1)
                    {
                        c1++;
                    }
                }
            }

            // b s b s
            lol c2 = 0;
            for (lol j = 0; j < m; j++)
            {
                lol v = b[0][j] - '0';
                v += b[1][j] - '0';
                if (j % 2 != 0)
                {
                    if (v == 1)
                    {
                        c2++;
                    }
                }
                else
                {
                    if (v != 1)
                    {
                        c2++;
                    }
                }
            }
            cout << min(c1, c2) << '\n';
        }
        else
        {
            lol v[m];
            for (lol i = 0; i < m; i++)
            {
                v[i] = 0;
                if (a[0][i] == '1')
                {
                    v[i] |= 1;
                }
                if (a[1][i] == '1')
                {
                    v[i] |= 2;
                }
                if (a[2][i] == '1')
                    v[i] |= 4;
            }
            bool val[8][8];
            for (lol i = 0; i < 8; i++)
            {
                for (lol j = 0; j < 8; j++)
                {
                    lol a2 = i, a3 = j;
                    lol a4 = i, a5 = j;
                    a2 &= 3;
                    a3 &= 3;
                    a4 &= 6;
                    a5 &= 6;
                    lol c = __builtin_popcount(a2) + __builtin_popcount(a3);
                    if (c % 2 != 0)
                    {
                        c = __builtin_popcount(a4) + __builtin_popcount(a5);
                        if (c % 2 != 0)
                            val[i][j] = true;
                        else
                            val[i][j] = false;
                    }
                    else
                        val[i][j] = false;
                }
            }

            lol dp[8][m];
            lol ans = LONG_LONG_MAX;
            for (lol i = 0; i < m; i++)
            {
                for (lol j = 0; j < 8; j++)
                {
                    if (i == 0)
                    {
                        dp[j][i] = __builtin_popcount((j ^ v[i]));
                    }
                    else
                    {
                        dp[j][i] = LONG_LONG_MAX;
                        for (lol k = 0; k < 8; k++)
                        {
                            if (val[k][j] && dp[k][i - 1] != LONG_LONG_MAX)
                            {
                                dp[j][i] = min(dp[j][i], dp[k][i - 1] + __builtin_popcount((j ^ v[i])));
                            }
                        }
                    }
                    if (i == m - 1)
                        ans = min(ans, dp[j][i]);
                }
            }
            cout << ans;
        }
    }
}