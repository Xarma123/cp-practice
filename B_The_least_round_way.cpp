#include <bits/stdc++.h>
#define lol long long
using namespace std;

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n;
    cin >> n;
    lol a[n][n];
    for (lol i = 0; i < n; i++)
    {
        for (lol j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }
    lol dp2[n][n];
    lol dp5[n][n];
    lol f[n][n];
    bool cc = false;
    for (lol i = 0; i < n; i++)
    {
        for (lol j = 0; j < n; j++)
        {
            f[i][j] = 0;
            if (a[i][j] == 0)
            {
                cc = true;
                f[i][j] = 1e9;
                continue;
            }
            while (a[i][j] % 2 == 0)
            {
                f[i][j]++;
                a[i][j] /= 2;
            }
        }
    }

    for (lol i = 0; i < n; i++)
    {
        for (lol j = 0; j < n; j++)
        {
            if (i == 0 && j == 0)
                dp2[i][j] = f[i][j];
            else if (i == 0)
            {
                dp2[i][j] = f[i][j] + dp2[i][j - 1];
            }
            else if (j == 0)
            {
                dp2[i][j] = f[i][j] + dp2[i - 1][j];
            }
            else
            {
                dp2[i][j] = f[i][j] + min(dp2[i][j - 1], dp2[i - 1][j]);
            }
        }
    }
    for (lol i = 0; i < n; i++)
    {
        for (lol j = 0; j < n; j++)
        {
            f[i][j] = 0;
            if (a[i][j] == 0)
            {
                cc = true;
                f[i][j] = 1e9;
                continue;
            }
            while (a[i][j] % 5 == 0)
            {
                f[i][j]++;
                a[i][j] /= 5;
            }
        }
    }
    for (lol i = 0; i < n; i++)
    {
        for (lol j = 0; j < n; j++)
        {
            if (i == 0 && j == 0)
                dp5[i][j] = f[i][j];
            else if (i == 0)
            {
                dp5[i][j] = f[i][j] + dp5[i][j - 1];
            }
            else if (j == 0)
            {
                dp5[i][j] = f[i][j] + dp5[i - 1][j];
            }
            else
            {
                dp5[i][j] = f[i][j] + min(dp5[i][j - 1], dp5[i - 1][j]);
            }
        }
    }
    if (cc && dp2[n - 1][n - 1] && dp5[n - 1][n - 1])
    {
        for (lol i = 0; i < n; i++)
        {
            for (lol j = 0; j < n; j++)
            {
                if (a[i][j] == 0)
                {
                    cout << 1 << '\n';
                    lol a1 = n - 1 - i;
                    lol a2 = n - 1 - j;
                    while (i--)
                    {
                        cout << "D";
                    }
                    while (j--)
                    {
                        cout << "R";
                    }
                    while (a1--)
                    {
                        cout << "D";
                    }
                    while (a2--)
                    {
                        cout << "R";
                    }

                    return 0;
                }
            }
        }
    }
    if (dp2[n - 1][n - 1] < dp5[n - 1][n - 1])
    {
        lol i = n - 1, j = n - 1;
        string s = "";
        while (i > 0 || j > 0)
        {
            if (i - 1 >= 0 && j - 1 >= 0)
            {
                if (dp2[i - 1][j] <= dp2[i][j - 1])
                {
                    s.push_back('D');
                    i--;
                }
                else
                {
                    s.push_back('R');
                    j--;
                }
            }
            else if (i - 1 >= 0)
            {
                s.push_back('D');
                i--;
            }
            else
            {
                s.push_back('R');
                j--;
            }
        }
        cout << dp2[n - 1][n - 1] << '\n';
        reverse(s.begin(), s.end());
        cout << s;
    }
    else
    {
        lol i = n - 1, j = n - 1;
        string s = "";
        while (i > 0 || j > 0)
        {

            if (i - 1 >= 0 && j - 1 >= 0)
            {
                if (dp5[i - 1][j] <= dp5[i][j - 1])
                {
                    s.push_back('D');
                    i--;
                }
                else
                {
                    s.push_back('R');
                    j--;
                }
            }
            else if (i - 1 >= 0)
            {
                s.push_back('D');
                i--;
            }
            else
            {
                s.push_back('R');
                j--;
            }
        }
        cout << dp5[n - 1][n - 1] << '\n';
        reverse(s.begin(), s.end());
        cout << s;
    }

    return 0;
}