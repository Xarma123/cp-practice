#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol a, b, n;
    cin >> a >> b >> n;
    while (n--)
    {
        lol l, t, m;
        cin >> l >> t >> m;
        lol st = l - 1, e = 1e12;
        while (st != e - 1)
        {
            lol md = (st + e) / 2ll;
            if (md == l - 1)
                st = l - 1;
            else
            {
                lol mx = a + b * 1ll * (md - 1);
                lol sum = (md - l + 1) * 1ll * (mx + a + b * 1ll * (l - 1)) / 2ll;
                if (mx <= t && sum <= m * 1ll * t)
                    st = md;
                else
                    e = md;
            }
        }
        if (st != l - 1)
            cout << st << '\n';
        else
            cout << -1 << '\n';
    }

    return 0;
}