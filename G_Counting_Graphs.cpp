#include <bits/stdc++.h>
using namespace std;
#define lol long long
class dsu
{
public:
    vector<lol> sz, p;
    dsu(lol n)
    {
        sz.assign(n + 1, 1);
        p.assign(n + 1, 0);
    }
    lol find(lol a)
    {
        if (p[a] == 0)
            return a;
        return p[a] = find(p[a]);
    }
    void unio(lol a, lol b)
    {
        a = find(a);
        b = find(b);
        if (a == b)
            return;
        if (sz[a] <= sz[b])
        {
            p[a] = b;
            sz[b] += sz[a];
        }
        else
        {
            p[b] = a;
            sz[a] += sz[b];
        }
    }
    lol size(lol a)
    {
        return sz[find(a)];
    }
};
lol bpow(lol a, lol b, lol m)
{
    lol ans = 1;
    while (b > 0)
    {
        if ((b & 1ll))
        {
            ans = (ans * 1ll * a) % m;
        }
        a = (a * 1ll * a) % m;
        b >>= 1;
    }
    return ans;
}
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
        lol n, S;
        cin >> n >> S;
        vector<pair<lol, pair<lol, lol>>> v;
        for (lol i = 0; i < n - 1; i++)
        {
            lol a, b, c;
            cin >> a >> b >> c;
            v.push_back({c, {a, b}});
        }
        sort(v.begin(), v.end());
        dsu d(n);
        lol ans = 1;
        for (auto e : v)
        {
            if (e.first >= S)
                break;

            lol a = d.size(e.second.first);
            lol b = d.size(e.second.second);
            lol x = S - e.first + 1;

            ans = (ans * 1ll * bpow(x, a * 1ll * b - 1, mod)) % mod;
            ans %= mod;
            d.unio(e.second.first, e.second.second);
        }
        cout << ans << '\n';
    }
}