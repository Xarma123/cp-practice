#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n;
    cin >> n;
    lol a[n];
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    bool p[31];
    memset(p, true, sizeof(p));
    vector<lol> all;
    for (lol i = 2; i < 31; i++)
    {
        if (p[i])
        {
            all.push_back(i);
            for (lol j = i * 1ll * i; j < 31; j += i)
            {
                p[j] = false;
            }
        }
    }
    map<lol, lol> mp;
    for (lol i = 0; i < (1ll << 10); i++)
    {
        lol v = 1;
        for (lol j = 0; j < 10; j++)
        {
            if ((i & (1ll << j)))
            {
                v = v * 1ll * all[j];
            }
        }

        if (v != 1)
        {
            mp[v] = 0;
        }
    }

    vector<lol> avl;
    for (lol i = 0; i < n; i++)
    {
        if (mp.count(a[i]))
            avl.push_back(a[i]);
    }
    lol m = 1e9 + 7;
    for (lol i = 0; i < avl.size(); i++)
    {
        mp[avl[i]]++;
        mp[avl[i]] %= m;
        for (auto j = mp.rbegin(); j != mp.rend(); j++)
        {
            pair<lol, lol> e = (*j);
            lol c = e.first * 1ll * avl[i];
            if (mp.count(c))
            {
                mp[c] += e.second;
                mp[c] %= m;
            }
        }
    }
    lol ans = 0;
    for (auto e : mp)
    {
        ans += e.second;
        ans %= m;
    }
    cout << ans;
}