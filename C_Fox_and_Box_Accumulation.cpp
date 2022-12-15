#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n;
    cin >> n;

    map<lol, lol> f, mp;
    for (lol i = 0; i < n; i++)
    {
        lol q;
        cin >> q;
        f[q]++;
    }
    for (auto e : f)
    {
        for (lol i = e.first; i >= 0; i--)
        {
            if (mp[i] == 0)
                continue;
            if (mp[i] * 1ll * (e.first + 1 - i) >= e.second)
            {
                lol a1 = e.second / mp[i];
                lol r = e.second % mp[i];
                lol tot = mp[i];

                mp[a1 + i] += tot - r;
                mp[i] -= tot - r;
                mp[i + a1 + 1] += r;
                mp[i] -= r;

                e.second = 0;
            }
            else
            {
                e.second -= mp[i] * 1ll * (e.first + 1 - i);
                mp[e.first + 1] += mp[i];
                mp[i] = 0;
            }
        }
        if (e.second != 0)
        {

            mp[e.first + 1] += e.second / (e.first + 1);

            if (e.second % (e.first + 1) != 0)
                mp[e.second % (e.first + 1)]++;
        }
    }
    lol ans = 0;
    for (auto e : mp)
    {
       
        ans += e.second;
    }
    cout << ans;

    return 0;
}