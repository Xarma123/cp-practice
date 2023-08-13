#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol t;
    cin >> t;
    while (t--)
    {
        lol n, s, k;
        cin >> n >> s >> k;
        lol a[k];
        lol h = s, l = s;
        set<lol> x;
        for (lol i = 0; i < k; i++)
        {
            cin >> a[i];
            x.insert(a[i]);
        }
        while (x.count(h))
            h++;
        while (x.count(l))
            l--;
        lol ans = LONG_LONG_MAX;
        if (h <= n)
            ans = min(ans, h - s);
        if (l >= 1)
        {
            ans = min(ans, s - l);
        }
        cout << ans << '\n';
    }
}