#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, s;
    cin >> n >> s;
    vector<vector<lol>> v;
    lol tot = s;
    while (n--)
    {
        lol x, y, k;
        cin >> x >> y >> k;
        v.push_back({x, y, k});
        tot += k;
    }
    if (tot < 1000000)
    {
        cout << -1;
    }
    else
    {
        long double st = -1, e = 1e18;
        while (abs(st - e) > 1e-6)
        {
            long double m = st + (e - st) / (long double)2;
           
            if (abs(m - st) <= 1e-6)
            {
                st = m;
            }
            else
            {
                lol c = s;
                for (auto e : v)
                {
                    lol x = e[0], y = e[1], q = e[2];
                    if ((long double)(x * 1ll * x + y * 1ll * y) <= powl(m, 2))
                        c += q;
                }
                if (c >= 1000000)
                {
                    e = m;
                }
                else
                    st = m;
            }
        }
        cout << fixed << setprecision(9) << e;
    }

    return 0;
}