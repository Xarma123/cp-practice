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
    lol mod = 998244353;
    while (t--)
    {
        lol n, m;
        cin >> n >> m;
        lol a[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        lol ans = 1;
        for (lol i = 1; i < n; i++)
        {
            if (a[i - 1] % a[i] != 0)
            {
                ans = 0;
                break;
            }
            lol q = a[i - 1] / a[i];
            vector<lol> p;
            for (lol j = 2; j * 1ll * j <= q; j++)
            {
                while (q % j == 0)
                {
                    if (p.size() == 0)
                        p.push_back(j);
                    else if (p.back() != j)
                        p.push_back(j);
                    q /= j;
                }
            }
            if (q > 1)
                p.push_back(q);
            lol sub = 0;
            lol hmm = m / a[i];
            for (lol j = 0; j < (1ll << (p.size())); j++)
            {
                lol v = 1;
                lol x = -1;
                for (lol k = 0; k < p.size(); k++)
                {
                    if (j & (1ll << k))
                    {
                        x *= -1;
                        v = v * 1ll * p[k];
                    }
                }
                if (v > 1)
                    sub += (hmm / v) * 1ll * x;
            }
            hmm -= sub;
            ans = (ans * 1ll * hmm) % mod;
        }
        cout << ans << '\n';
    }

    return 0;
}