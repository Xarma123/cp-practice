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
        lol cl = -1, cr = -1;
        lol rl = -1, rr = -1;
        for (lol i = 0; i < n; i++)
        {
            for (lol j = 0; j < m; j++)
            {
                if (a[i][j] == 'P')
                {
                    if (cl == -1)
                    {
                        cl = j;
                        cr = j;
                    }
                    else
                    {
                        cl = min(cl, j);
                        cr = max(cr, j);
                    }

                    rr = i;
                    if (rl == -1)
                        rl = i;
                }
            }
        }
        if (cl == -1)
        {
            cout << 0 << '\n';
            continue;
        }
        bool one = false;
        for (lol i = 0; i < rl; i++)
        {
            lol c = 0;
            for (lol j = cl; j <= cr; j++)
            {
                if (a[i][j] == 'A')
                    c++;
            }
            if (c == cr - cl + 1)
            {
                one = true;
            }
        }
        for (lol i = rr + 1; i < n; i++)
        {
            lol c = 0;
            for (lol j = cl; j <= cr; j++)
            {
                if (a[i][j] == 'A')
                    c++;
            }
            if (c == cr - cl + 1)
            {
                one = true;
            }
        }
        for (lol j = 0; j < cl; j++)
        {
            lol c = 0;
            for (lol i = rl; i <= rr; i++)
            {
                if (a[i][j] == 'A')
                    c++;
            }
            if (c == rr - rl + 1)
                one = true;
        }
        for (lol j = cr + 1; j < m; j++)
        {
            lol c = 0;
            for (lol i = rl; i <= rr; i++)
            {
                if (a[i][j] == 'A')
                    c++;
            }
            if (c == rr - rl + 1)
                one = true;
        }
        if (one)
        {
            cout << 1 << '\n';
            continue;
        }
        if (a[0][0] == 'A' || a[0][m - 1] == 'A' || a[n - 1][0] == 'A' || a[n - 1][m - 1] == 'A')
        {
            cout << 2 << '\n';
            continue;
        }
        bool tw = false;
        for (lol i = 0; i < n; i++)
        {
            lol c = 0;
            for (lol j = 0; j < m; j++)
            {
                if (a[i][j] == 'A')
                    c++;
            }
            if (c == m)
                tw = true;
        }
        for (lol j = 0; j < m; j++)
        {
            lol c = 0;
            for (lol i = 0; i < n; i++)
            {
                if (a[i][j] == 'A')
                    c++;
            }
            if (c == n)
                tw = true;
        }
        if (tw)
        {
            cout << 2 << '\n';
            continue;
        }

        bool three = false;
        for (lol j = 0; j < m; j++)
        {
            if (a[0][j] == 'A')
                three = true;
            if (a[n - 1][j] == 'A')
                three = true;
        }
        for (lol i = 0; i < n; i++)
        {
            if (a[i][0] == 'A')
                three = true;
            if (a[i][m - 1] == 'A')
                three = true;
        }
        if (three)
        {
            cout << 3 << '\n';
            continue;
        }
        bool f = false;
        for (lol i = 0; i < n; i++)
        {
            for (lol j = 0; j < m; j++)
            {
                if (a[i][j] == 'A')
                    f = true;
            }
        }
        if (f)
            cout << 4 << '\n';
        else
            cout << "MORTAL\n";
    }
}