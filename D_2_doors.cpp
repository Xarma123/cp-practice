#include <bits/stdc++.h>
#define lol long long
using namespace std;

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, q;
    cin >> n >> q;
    lol a[n];
    memset(a, 0ll, sizeof(a));

    map<lol, vector<pair<lol, lol>>> mp;
    while (q--)
    {
        lol i, j, x;
        cin >> i >> j >> x;
        for (lol k = 31; k >= 0; k--)
        {
            if ((!(x & (1ll << k))))
            {
                a[i - 1] |= (1ll << k);
                a[j - 1] |= (1ll << k);
            }
        }
        if (i > j)
            swap(i, j);
        mp[i].push_back({j, x});
    }

    lol ans[n];
    memset(ans, 0ll, sizeof(ans));
    for (lol k = 32; k >= 0; k--)
    {
        for (auto e : mp)
        {
            lol i = e.first;
            bool f = false;
            if (ans[i - 1] & (1ll << k))
                continue;
            for (auto p : e.second)
            {
                lol j = p.first;
                lol x = p.second;
                if ((x & (1ll << k)) && (a[j - 1] & (1ll << k)))
                {
                    f = true;
                }
                if ((x & (1ll << k)) && i == j)
                {
                    f = true;
                }
            }
            if (f)
            {
                ans[i - 1] |= (1ll << k);
            }
            else
            {
                for (auto p : e.second)
                {
                    lol j = p.first;
                    lol x = p.second;
                    if ((x & (1ll << k)))
                    {
                        ans[j - 1] |= (1ll << k);
                    }
                }
            }
        }
    }
    for (lol i = 0; i < n; i++)
        cout << ans[i] << ' ';

    return 0;
}