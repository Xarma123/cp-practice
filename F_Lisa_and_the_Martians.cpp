#include <bits/stdc++.h>
using namespace std;
#define lol long long
lol a[200005];
vector<pair<lol, lol>> v;
void solve(vector<lol> in, lol k)
{
    if (in.size() == 0)
        return;
    if (k < 0ll && (long long)in.size() > 1ll)
    {
        v.push_back({in[0], in.back()});
        return;
    }
    if (k < 0)
        return;
    if ((long long)in.size() == 2ll)
    {
        v.push_back({in[0], in.back()});
        return;
    }
    vector<lol> l, r;
    for (lol i = 0; i < in.size(); i++)
    {
        if ((a[in[i]] & (1ll << k)))
        {
            l.push_back(in[i]);
        }
        else
            r.push_back(in[i]);
    }
    solve(l, k - 1);
    solve(r, k - 1);
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol t;
    cin >> t;
    while (t--)
    {
        v.clear();
        lol n, k;
        cin >> n >> k;
        vector<lol> x;
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
            x.push_back(i);
        }
        solve(x, k - 1);
        lol mx = LONG_LONG_MIN;
        lol ansi, ansj, ansx;
        for (auto e : v)
        {
            lol f = e.first, s = e.second;
            lol x = 0ll;
            for (lol i = 0; i < k; i++)
            {
                if ((a[f] & (1ll << i)) == (a[s] & (1ll << i)))
                {
                    if (!(a[f] & (1ll << i)))
                        x |= (1ll << i);
                }
            }
            lol here = ((a[f] ^ x) & (a[s] ^ x));
            if (mx < here)
            {
                mx = here;
                ansi = f + 1;
                ansj = s + 1;
                ansx = x;
            }
        }
        cout << ansi << " " << ansj << " " << ansx << '\n';
    }
}