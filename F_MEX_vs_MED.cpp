#include <bits/stdc++.h>
#define lol long long
using namespace std;
class q1;
class qq
{
public:
    qq()
    {
        cout << 21;
    }
    void f(q1 b)
    {
        cout << b.a;
    }
    friend class q1;
};
class q1
{
    lol a;
};

int main()
{
    qq qqq;
    q1 qqqq;

    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol t;
    cin >> t;
    while (t--)
    {
        lol n;
        cin >> n;
        lol p[n];
        map<lol, lol> ind;
        for (lol i = 0; i < n; i++)
        {
            cin >> p[i];
            ind[p[i]] = i;
        }
        lol l = LONG_LONG_MAX, r = LONG_LONG_MIN;
        lol ans = 0;
        for (lol i = 0; i < n; i++)
        {
            if (l > ind[i] || r < ind[i])
            {
                l = min(l, ind[i]);
                r = max(r, ind[i]);
            }

            lol x = 2ll * i + 1;
            if (r - l + 1 == x)
            {
                ans++;
            }
            else if (r - l + 1 < x)
            {
                lol need = x - r + l - 1;
                if (n - r + l - 1 >= need)
                {
                    lol st = max(l - need, 0ll);
                    lol end = min(n - r + l - 1 - need, l);
                    ans += end - st + 1;
                }
            }
            x++;
            if (r - l + 1 == x)
            {
                ans++;
            }
            else if (r - l + 1 < x)
            {
                lol need = x - r + l - 1;

                if (n - r + l - 1 >= need)
                {
                    lol st = max(l - need, 0ll);
                    lol end = min(n - r + l - 1 - need, l);
                    ans += end - st + 1;
                }
            }
        }
        cout << ans << '\n';
    }

    return 0;
}