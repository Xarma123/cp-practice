#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, m;
    while (cin >> n >> m)
    {
       
        lol a[n][m];
        lol dp[n][m];
        for (lol i = 0; i < n; i++)
        {
            for (lol j = 0; j < m; j++)
            {
                cin >> a[i][j];
                if (j == m - 1)
                    dp[i][j] = a[i][j];
            }
        }
        lol parent[n][m];
        for (lol j = m - 2; j >= 0; j--)
        {
            for (lol i = 0; i < n; i++)
            {
                dp[i][j] = LONG_LONG_MAX;

                if (i + 1 >= n)
                {
                    if (dp[i][j] > dp[0][j + 1])
                    {
                        parent[i][j] = 0;
                    }
                    dp[i][j] = min(dp[i][j], dp[0][j + 1]);
                }

                if (i - 1 >= 0)
                {
                    if (dp[i][j] > dp[i - 1][j + 1])
                    {
                        parent[i][j] = i - 1;
                    }
                    dp[i][j] = min(dp[i][j], dp[i - 1][j + 1]);
                }

                if (i + 1)
                {
                    if (dp[i][j] > dp[i][j + 1])
                    {
                        parent[i][j] = i;
                    }
                    dp[i][j] = min(dp[i][j], dp[i][j + 1]);
                }

                if (i + 1 < n)
                {
                    if (dp[i][j] > dp[i + 1][j + 1])
                    {
                        parent[i][j] = i + 1;
                    }
                    dp[i][j] = min(dp[i][j], dp[i + 1][j + 1]);
                }

                if (i - 1 < 0)
                {
                    if (dp[i][j] > dp[n - 1][j + 1])
                    {
                        parent[i][j] = n - 1;
                    }
                    dp[i][j] = min(dp[i][j], dp[n - 1][j + 1]);
                }

                dp[i][j] += a[i][j];
            }
        }

        lol st = 0;
        for (lol i = 0; i < n; i++)
        {
            if (dp[i][0] < dp[st][0])
                st = i;
        }
        lol v = st;

        cout << st + 1;
        for (lol i = 0; i < m - 1; i++)
        {
            cout << " " << parent[st][i] + 1;
            st = parent[st][i];
        }
        cout << endl;
        st = v;
        cout << dp[st][0] << endl;
    }
    return 0;
}