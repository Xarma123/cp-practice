#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        lol n, m;
        cin >> n >> m;
        lol a[n];
        map<lol, lol> l, co;
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
            l[a[i]] = 0;
        }
        for (lol j = 1; j <= m; j++)
        {
            lol p, v;
            cin >> p >> v;
            p--;
            co[a[p]] += j - l[a[p]];
            l.erase(a[p]);
            a[p] = v;
            l[a[p]] = j;
        }
        for (auto e : l)
        {
            co[e.first] += m + 1 - e.second;
        }
        lol ans = ((m)*1ll * (m + 1) / 2ll) * 1ll * (2ll * n);
        for (auto e : co)
        {
            ans -= e.second * 1ll * (e.second - 1) / 2ll;
        }
        cout << ans << '\n';
    }
}