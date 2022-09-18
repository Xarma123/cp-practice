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
        lol tot = 0;
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
            for (lol j = 0; j < m; j++)
            {
                if (a[i][j] == '1')
                    tot++;
            }
        }

        if (tot == n * m)
        {
            cout << tot - 2 << endl;
        }
        else
        {
            bool f = true;
            for (lol i = 0; i < n; i++)
            {
                for (lol j = 0; j < m - 1; j++)
                {
                    if (a[i][j] == '0' && a[i][j + 1] == '0')
                        f = false;
                }
            }
            for (lol j = 0; j < m; j++)
            {
                for (lol i = 0; i < n - 1; i++)
                {
                    if (a[i][j] == '0' && a[i + 1][j] == '0')
                        f = false;
                }
            }
            for (lol i = 0; i < n; i++)
            {
                for (lol j = 0; j < m; j++)
                {
                    if (a[i][j] == '1')
                    {
                        if (i - 1 >= 0 && j + 1 < m && a[i - 1][j] == '0' && a[i][j + 1] == '0')
                            f = false;
                        if (i - 1 >= 0 && j - 1 >= 0 && a[i - 1][j] == '0' && a[i][j - 1] == '0')
                            f = false;
                        if (i + 1 < n && j + 1 < m && a[i + 1][j] == '0' && a[i][j + 1] == '0')
                            f = false;
                        if (i + 1 < n && j - 1 >= 0 && a[i + 1][j] == '0' && a[i][j - 1] == '0')
                            f = false;
                    }
                }
            }

            if (!f)
                cout << tot << endl;
            else
            {
                if (tot == 2)
                    cout << 1 << endl;
                else
                {
                    cout << 1 + tot - 2 << endl;
                }
            }
        }
    }

    return 0;
}