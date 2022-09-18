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
        lol n;
        cin >> n;
        string s[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> s[i];
        }
        lol r1 = -1, c1, r2, c2;
        for (lol i = 0; i < n; i++)
        {
            for (lol j = 0; j < n; j++)
            {
                if (s[i][j] == '*')
                {
                    if (r1 == -1)
                    {
                        r1 = i;
                        c1 = j;
                    }
                    else
                    {
                        r2 = i;
                        c2 = j;
                    }
                }
            }
        }
        if (r1 == r2)
        {
            if (r1 - 1 >= 0)
            {
                s[r1 - 1][c1] = '*';
                s[r1 - 1][c2] = '*';
            }
            else
            {
                s[r1 + 1][c1] = '*';
                s[r1 + 1][c2] = '*';
            }
        }
        else if (c1 == c2)
        {
            if (c1 - 1 >= 0)
            {
                s[r1][c1 - 1] = '*';
                s[r2][c1 - 1] = '*';
            }
            else
            {
                s[r1][c1 + 1] = '*';
                s[r2][c1 + 1] = '*';
            }
        }
        else
        {
            s[r1][c2] = '*';
            s[r2][c1] = '*';
        }

        for (lol i = 0; i < n; i++)
        {
            cout << s[i] << endl;
        }
    }

    return 0;
}