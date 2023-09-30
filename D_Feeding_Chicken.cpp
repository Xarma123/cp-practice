#include <bits/stdc++.h>
using namespace std;
#define lol long long
// a
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol t;
    cin >> t;
    while (t--)
    {
        lol n, m, k;
        cin >> n >> m >> k;
        string a[n];
        lol r = 0;
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
            for (lol j = 0; j < m; j++)
            {
                if (a[i][j] == 'R')
                    r++;
            }
        }
        lol v = r / k;
        lol ex = r % k;
        lol ans[n][m];
        lol c = 0;
        lol g = v;
        if (ex > 0)
            g++, ex--;
        for (lol i = 0; i < n; i++)
        {

            if (i % 2 == 0)
            {

                for (lol j = 0; j < m; j++)
                {

                    c = min(c, k - 1);
                    if (a[i][j] == '.')
                    {
                        ans[i][j] = c;
                    }
                    else
                    {
                        g--;
                        ans[i][j] = c;
                        if (g == 0)
                        {
                            c++;
                            g = v;
                            if (ex > 0)
                            {
                                g++;
                                ex--;
                            }
                        }
                    }
                }
            }
            else
            {

                for (lol j = m - 1; j >= 0; j--)
                {
                    c = min(c, k - 1);
                    if (a[i][j] == '.')
                    {
                        ans[i][j] = c;
                    }
                    else
                    {
                        g--;
                        ans[i][j] = c;
                        if (g == 0)
                        {
                            c++;
                            g = v;
                            if (ex > 0)
                            {
                                g++;
                                ex--;
                            }
                        }
                    }
                }
            }
        }
        for (lol i = 0; i < n; i++)
        {
            for (lol j = 0; j < m; j++)
            {
                if (ans[i][j] < 26)
                {
                    cout << char('a' + ans[i][j]);
                }
                else if (ans[i][j] < 52)
                {
                    cout << char('A' + ans[i][j] - 26);
                }
                else
                    cout << ans[i][j] - 52;
            }
            cout << '\n';
        }
    }
}