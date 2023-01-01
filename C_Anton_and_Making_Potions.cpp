#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, m, k;
    cin >> n >> m >> k;
    lol x, s;
    cin >> x >> s;
    pair<lol, lol> a[m];
    for (lol i = 0; i < m; i++)
    {
        cin >> a[i].first;
    }
    for (lol i = 0; i < m; i++)
    {
        cin >> a[i].second;
    }
    pair<lol, lol> b[k];
    for (lol i = 0; i < k; i++)
    {
        cin >> b[i].second;
    }
    for (lol i = 0; i < k; i++)
    {
        cin >> b[i].first;
    }
    sort(b, b + k);
    lol mx[k];
    for (lol i = 0; i < k; i++)
    {
        if (i == 0)
            mx[i] = b[i].second;
        else
        {
            mx[i] = max(mx[i - 1], b[i].second);
        }
    }
    lol ans = n * 1ll * x;
    for (lol i = 0; i <= m; i++)
    {
        lol cs;
        if (i)
            cs = s - a[i - 1].second;
        else
            cs = s;
        if (cs < 0)
            continue;
        lol cx;
        if (i)
            cx = a[i - 1].first;
        else
            cx = x;
        lol st = -1, e = k;
        while (st != e - 1)
        {
            lol md = (st + e) / 2;
            if (md == -1)
            {
                st = md;
            }
            else if (md == k)
                e = md;
            else if (b[md].first <= cs)
            {
                st = md;
            }
            else
                e = md;
        }
        lol r = 0;
        if (st != -1)
        {
            r = mx[st];
        }
        ans = min(ans, max(n - r, 0ll) * 1ll * cx);
    }
    cout << ans;

    return 0;
}