#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s;
    cin >> s;
    lol nb, ns, nc;
    cin >> nb >> ns >> nc;
    lol pb, ps, pc;
    cin >> pb >> ps >> pc;
    lol cb, cs, cc;
    cb = cs = cc = 0;
    for (auto c : s)
    {
        if (c == 'B')
            cb++;
        else if (c == 'S')
            cs++;
        else
            cc++;
    }
    lol r;
    cin >> r;
    lol l = 0, h = 1e14;
    while (l != h - 1)
    {
        lol m = (l + h) / 2;
        lol c = 0;
        if (nb < m * 1ll * cb)
        {
            c += pb * 1ll * (m * 1ll * cb - nb);
        }
        if (ns < m * 1ll * cs)
        {
            c += ps * 1ll * (m * 1ll * cs - ns);
        }
        if (nc < m * 1ll * cc)
        {
            c += pc * 1ll * (m * 1ll * cc - nc);
        }
        if (c <= r)
            l = m;
        else
            h = m;
    }
    cout << l;

    return 0;
}