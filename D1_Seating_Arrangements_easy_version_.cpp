#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        lol n, m;
        cin >> n;
        cin >> m;
        lol a[n][m];
        bool s[n][m];
        for (lol i = 0; i < n; i++)
        {

            for (lol j = 0; j < m; j++)
            {
                cin >> a[i][j];
                s[i][j] = false;
            }
        }
        lol ans = 0;
        for (lol I = 0; I < n; I++)
        {

            for (lol J = 0; J < m; J++)
            {
                lol k = a[I][J];

                if (k % m == 0)
                {
                    lol r = k / m - 1;
                    lol c = m - 1;

                    lol rg;
                    lol cg;
                    bool give = false;
                    for (lol i = r; i >= 0; i--)
                    {
                        for (lol j = m - 1; j >= 0; j--)
                        {
                            if (i == r)
                            {
                                if (j <= c)
                                {
                                    if (!s[i][j])
                                    {
                                        s[i][j] = true;
                                        give = true;
                                        rg = i;
                                        cg = j;
                                        break;
                                    }
                                }
                            }
                            else
                            {
                                if (!s[i][j])
                                {
                                    s[i][j] = true;
                                    give = true;
                                    rg = i;
                                    cg = j;
                                    break;
                                }
                            }
                        }
                        if (give)
                            break;
                    }
                    if (!give)
                    {
                        for (lol i = r; i < n; i++)
                        {
                            for (lol j = 0; j < m; j++)
                            {
                                if (i == r)
                                {
                                    if (j > c)
                                    {
                                        if (!s[i][j])
                                        {
                                            s[i][j] = true;
                                            give = true;
                                            rg = i;
                                            cg = j;
                                            break;
                                        }
                                    }
                                }
                                else
                                {
                                    if (!s[i][j])
                                    {
                                        s[i][j] = true;
                                        give = true;
                                        rg = i;
                                        cg = j;
                                        break;
                                    }
                                }
                            }
                            if (give)
                                break;
                        }
                    }
                    cout << rg << ' ' << cg << endl;
                    for (lol i = 0; i < cg; i++)
                    {
                        if (s[rg][i])
                            ans++;
                    }
                }
                else
                {
                    lol r = k / m;
                    lol c = k % m - 1;
                    lol seat = a[r][c];
                    lol rg;
                    lol cg;
                    bool give = false;
                    for (lol i = r; i >= 0; i--)
                    {
                        for (lol j = m - 1; j >= 0; j--)
                        {
                            if (i == r)
                            {
                                if (j <= c)
                                {
                                    if (!s[i][j])
                                    {
                                        s[i][j] = true;
                                        give = true;
                                        rg = i;
                                        cg = j;
                                        break;
                                    }
                                }
                            }
                            else
                            {
                                if (!s[i][j])
                                {
                                    s[i][j] = true;
                                    give = true;
                                    rg = i;
                                    cg = j;
                                    break;
                                }
                            }
                        }
                        if (give)
                            break;
                    }
                    if (!give)
                    {
                        for (lol i = r; i < n; i++)
                        {
                            for (lol j = 0; j < m; j++)
                            {
                                if (i == r)
                                {
                                    if (j > c)
                                    {
                                        if (!s[i][j])
                                        {
                                            s[i][j] = true;
                                            give = true;
                                            rg = i;
                                            cg = j;
                                            break;
                                        }
                                    }
                                }
                                else
                                {
                                    if (!s[i][j])
                                    {
                                        s[i][j] = true;
                                        give = true;
                                        rg = i;
                                        cg = j;
                                        break;
                                    }
                                }
                            }
                            if (give)
                                break;
                        }
                    }
                    for (lol i = 0; i < cg; i++)
                    {
                        if (s[rg][i])
                            ans++;
                    }
                    cout << rg << ' ' << cg << endl;
                }
            }
        }
        cout << ans << endl;
    }

    return 0;
}