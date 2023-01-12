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
        lol a[n];
        pair<lol, lol> b[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
            b[i].first = a[i];
            b[i].second = i + 1;
        }
        sort(b, b + n);
        lol st = 0, e = n + 1;
        while (st != e - 1)
        {
            lol md = (st + e) / 2;
            if (md == 0)
            {
                st = md;
            }
            else if (md == n + 1)
                e = md;
            else
            {

                lol cost = LONG_LONG_MAX;
                if (n - 1 >= md)
                {
                    lol cn = 0;
                    lol q = md;
                    for (lol i = 0; i < n; i++)
                    {
                        if (b[i].second == md)
                            continue;
                        if (q == 0)
                            break;
                        q--;
                        cn += b[i].first;
                    }
                    cost = min(cost, cn);
                }
                lol cn = a[md - 1];
                lol r = max(md - 2, 0ll);
                if (n - 1 >= r)
                {
                    for (lol i = 0; i < n; i++)
                    {
                        if (b[i].second == md)
                            continue;
                        if (r == 0)
                            break;
                        r--;
                        cn += b[i].first;
                    }
                }
                cost = min(cost, cn);
                if (cost <= m)
                    st = md;
                else
                    e = md;
            }
        }
        cout << n - st + 1 << '\n';
    }

    return 0;
}