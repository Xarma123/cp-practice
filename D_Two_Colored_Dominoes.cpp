#include <bits/stdc++.h>
using namespace std;
#define lol long long
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
        char c[n][m];
        memset(c, '.', sizeof(c));
        for (lol j = 0; j < m; j++)
        {
            bool f = false;

            for (lol i = 0; i < n; i++)
            {
                if (a[i][j] == 'L')
                {
                    if (f)
                    {
                        c[i][j] = 'B';
                        c[i][j + 1] = 'W';
                        f = false;
                    }
                    else
                    {
                        c[i][j] = 'W';
                        c[i][j + 1] = 'B';
                        f = true;
                    }
                }
            }
        }
        for (lol i = 0; i < n; i++)
        {
            bool f = false;
            for (lol j = 0; j < m; j++)
            {
                if (a[i][j] == 'U')
                {

                    if (f)
                    {
                        c[i][j] = 'B';
                        c[i + 1][j] = 'W';
                        f = false;
                    }
                    else
                    {
                        c[i][j] = 'W';
                        c[i + 1][j] = 'B';
                        f = true;
                    }
                }
            }
        }
        bool ans = true;
        for (lol i = 0; i < n; i++)
        {
            lol f = 0;
            for (lol j = 0; j < m; j++)
            {
                if (c[i][j] == 'W')
                    f++;
                else if (c[i][j] == 'B')
                    f--;
            }
            if (f != 0)
            {
                ans = false;
                break;
            }
        }

        for (lol j = 0; j < m; j++)
        {
            lol f = 0;
            for (lol i = 0; i < n; i++)
            {
                if (c[i][j] == 'W')
                    f++;
                else if (c[i][j] == 'B')
                    f--;
            }
            if (f != 0)
            {
                ans = false;
                break;
            }
        }
        if (ans)
        {
            for (lol i = 0; i < n; i++)
            {
                for (lol j = 0; j < m; j++)
                {
                    cout << c[i][j];
                }
                cout << endl;
            }
        }
        else
            cout << -1 << endl;
    }
}