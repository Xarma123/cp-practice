#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol a, b, c, d, n;
    cin >> a >> b >> c >> d >> n;
    lol x[n];
    for (lol i = 0; i < n; i++)
    {
        cin >> x[i];
    }
    char as[max(b, d)][a + c];
    memset(as, '\n', sizeof(as));
    if (b >= d)
    {
        lol p = 0;
        for (lol i = d; i < b; i++)
        {
            for (lol j = a; j < a + c; j++)
            {
                as[i][j] = '.';
            }
        }
        bool f;
        if ((b - d) % 2)
            f = true;
        else
            f = false;
        for (lol i = b - 1; i >= 0; i--)
        {
            if (f)
            {
                for (lol j = a + c - 1; j >= 0; j--)
                {
                    if (as[i][j] == '.')
                        continue;
                    as[i][j] = char('a' + p);
                    if (--x[p] == 0)
                        p++;
                }
            }
            else
            {
                for (lol j = 0; j < a + c; j++)
                {
                    if (as[i][j] == '.')
                        continue;
                    as[i][j] = char('a' + p);
                    if (--x[p] == 0)
                        p++;
                }
            }
            if (f)
                f = false;
            else
                f = true;
        }
    }
    else
    {
        lol p = 0;
        for (lol i = b; i < d; i++)
        {
            for (lol j = 0; j < a; j++)
            {
                as[i][j] = '.';
            }
        }
        bool f;
        if ((d - b) % 2)
            f = false;
        else
            f = true;
        for (lol i = d - 1; i >= 0; i--)
        {
            if (f)
            {
                for (lol j = a + c - 1; j >= 0; j--)
                {
                    if (as[i][j] == '.')
                        continue;
                    as[i][j] = char('a' + p);
                    if (--x[p] == 0)
                        p++;
                }
            }
            else
            {
                for (lol j = 0; j < a + c; j++)
                {
                    if (as[i][j] == '.')
                        continue;
                    as[i][j] = char('a' + p);
                    if (--x[p] == 0)
                        p++;
                }
            }
            if (f)
                f = false;
            else
                f = true;
        }
    }
    cout << "YES" << endl;
    for (lol i = 0; i < max(b, d); i++)
    {
        for (lol j = 0; j < a + c; j++)
        {
            cout << as[i][j];
        }
        cout << endl;
    }
    return 0;
}