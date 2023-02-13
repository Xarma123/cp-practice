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
        lol n, m, d;
        cin >> n >> m >> d;
        map<lol, lol> ind;
        for (lol i = 0; i < n; i++)
        {
            lol q;
            cin >> q;
            ind[q] = i;
        }
        lol a[m];
        lol ans = LONG_LONG_MAX;
        for (lol i = 0; i < m; i++)
        {
            cin >> a[i];
            if (i)
            {
                lol p = ind[a[i - 1]];
                lol nx = ind[a[i]];
               
                if (nx > p && nx <= p + d)
                {
                    ans = min(ans, nx - p);
                    if (p+n-1-nx>=p + d - nx + 1)
                    {
                        ans = min(ans, p + d - nx + 1);
                    }
                }
                else
                    ans = min(ans, 0ll);
            }
        }
        cout << ans << '\n';
    }

    return 0;
}