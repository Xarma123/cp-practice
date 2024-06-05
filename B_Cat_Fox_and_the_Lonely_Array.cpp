#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol t;
    cin >> t;
    while (t--)
    {
        lol n;
        cin >> n;
        lol a[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        lol c[n][30];
        for (lol i = 0; i < n; i++)
        {
            for (lol j = 0; j < 30; j++)
            {
                if ((a[i] & (1ll << j)))
                {
                    c[i][j] = 1;
                }
                else
                    c[i][j] = 0;
                if (i)
                {
                    c[i][j] += c[i - 1][j];
                }
            }
        }

        lol s = 0, e = n;
        while (s != e - 1)
        {
            lol m = (s + e) / 2ll;
            if (m == 0)
            {
                s = m;
            }
            else
            {
                lol ex = -1;
                bool f = true;
                for (lol i = m - 1; i < n; i++)
                {
                    lol val = 0;
                    for (lol j = 0; j < 30; j++)
                    {
                        lol v = c[i][j];
                        if (i - m >= 0)
                            v -= c[i - m][j];
                        if (v)
                            val |= (1ll << j);
                    }
                    if (ex == -1)
                        ex = val;
                    else if (ex != val)
                    {
                        f = false;
                    }
                }
                if (f)
                    e = m;
                else
                    s = m;
            }
        }
        cout << e << '\n';
    }

    return 0;
}
