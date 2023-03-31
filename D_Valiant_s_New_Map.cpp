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
        lol a[n][m];
        for (lol i = 0; i < n; i++)
        {
            for (lol j = 0; j < m; j++)
            {
                cin >> a[i][j];
            }
        }
        lol s = 0, e = 1e18;
        while (e != s + 1)
        {
            lol l = (e + s) / 2;
            if (l <= 1)
            {
                s = l;
            }
            else if (l > min(n, m))
            {
                e = l;
            }
            else
            {
                lol c[n + 1][m + 1];
                for (lol i = 0; i <= n; i++)
                {
                    for (lol j = 0; j <= m; j++)
                    {
                        if (i == 0 || j == 0)
                            c[i][j] = 0;
                        else if (a[i - 1][j - 1] >= l)
                            c[i][j] = 1;
                        else
                            c[i][j] = 0;
                    }
                }
                for (lol i = 0; i <= n; i++)
                {
                    for (lol j = 0; j <= m; j++)
                    {
                        if (j)
                            c[i][j] += c[i][j - 1];
                    }
                }
                for (lol i = 1; i <= n; i++)
                {
                    for (lol j = 0; j <= m; j++)
                    {
                        c[i][j] += c[i - 1][j];
                    }
                }
                bool f = false;
                for (lol i = 1; i < n - l + 2; i++)
                {
                    for (lol j = 1; j < m - l + 2; j++)
                    {
                        lol q = c[i + l - 1][j + l - 1] - c[i + l - 1][j - 1] - c[i - 1][j + l - 1] + c[i - 1][j - 1];
                        f |= (q == (l * 1ll * l));
                    }
                }
                if (f)
                    s = l;
                else
                    e = l;
            }
        }

        cout << s << '\n';
    }

    return 0;
}