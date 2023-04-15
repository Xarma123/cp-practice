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
        lol ans[n][m];
        memset(ans, 0ll, sizeof(ans));
        lol p[m];
        for (lol i = 0; i < n; i++)
        {
            lol l = -1, r = -1;
            for (lol j = 0; j < m; j++)
            {
                if (a[i][j] == 'B')
                {
                    l = j;
                    break;
                }
            }
            for (lol j = m - 1; j >= 0; j--)
            {
                if (a[i][j] == 'B')
                {
                    r = j;
                    break;
                }
            }
            if (i == 0)
            {
                if (l == -1)
                    memset(p, -1, sizeof(p));
                else
                {
                    for (lol j = 0; j < m; j++)
                    {
                        p[j] = max((long long)abs(j - l), (long long)abs(j - r));
                    }
                }
            }
            else
            {
                if (l == -1)
                {
                    for (lol j = 0; j < m; j++)
                    {
                        if (p[j] != -1)
                            p[j] = p[j] + 1ll;
                    }
                }
                else
                {
                    for (lol j = 0; j < m; j++)
                    {
                        if (p[j] != -1)
                        {
                            p[j] = max(p[j] + 1ll, max((long long)abs(j - l), (long long)abs(j - r)));
                        }
                        else
                            p[j] = max((long long)abs(j - l), (long long)abs(j - r));
                    }
                }
            }
            for (lol j = 0; j < m; j++)
            {
                ans[i][j] = max(ans[i][j], p[j]);
            }
        }
        for (lol i = n - 1; i >= 0; i--)
        {
            lol l = -1, r = -1;
            for (lol j = 0; j < m; j++)
            {
                if (a[i][j] == 'B')
                {
                    l = j;
                    break;
                }
            }
            for (lol j = m - 1; j >= 0; j--)
            {
                if (a[i][j] == 'B')
                {
                    r = j;
                    break;
                }
            }
            if (i == n - 1)
            {
                if (l == -1)
                    memset(p, -1, sizeof(p));
                else
                {
                    for (lol j = 0; j < m; j++)
                    {
                        p[j] = max((long long)abs(j - l), (long long)abs(j - r));
                    }
                }
            }
            else
            {
                if (l == -1)
                {
                    for (lol j = 0; j < m; j++)
                    {
                        if (p[j] != -1)
                            p[j] = p[j] + 1ll;
                    }
                }
                else
                {
                    for (lol j = 0; j < m; j++)
                    {
                        if (p[j] != -1)
                        {
                            p[j] = max(p[j] + 1ll, max((long long)abs(j - l), (long long)abs(j - r)));
                        }
                        else
                            p[j] = max((long long)abs(j - l), (long long)abs(j - r));
                    }
                }
            }
            for (lol j = 0; j < m; j++)
            {
                ans[i][j] = max(ans[i][j], p[j]);
            }
        }
        lol v = LONG_LONG_MAX;
        lol a1, a2;
        for (lol i = 0; i < n; i++)
        {
            for (lol j = 0; j < m; j++)
            {
                if (v > ans[i][j])
                {
                    v = ans[i][j];
                    a1 = i, a2 = j;
                }
            }
        }
        cout << a1 + 1 << " " << a2 + 1 << '\n';
    }

    return 0;
}