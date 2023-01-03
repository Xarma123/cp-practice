#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, m, w;
    cin >> n >> m >> w;
    lol a[n];
    lol st = 1e9 + 7;
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
        st = min(st, a[i]);
    }
    lol e = 1e18;
    while (st != e - 1)
    {
        lol md = (st + e) / 2;
        lol use = m;
        lol c[n];
        memset(c, 0, sizeof(c));
        lol i;
        lol q = 0;
        for (i = 0; i < n; i++)
        {
            q -= c[i];
            lol v = a[i] + q;
            if (v < md)
            {
                if (use - md + v >= 0)
                {
                    if (i + w - 1 < n)
                    {
                        if (i + w < n)
                            c[i + w] += md - v;
                    }
                    q += md - v;
                    use = use - md + v;
                }
                else
                    break;
            }
        }
        if (i == n)
            st = md;
        else
            e = md;
    }
    cout << st;

    return 0;
}