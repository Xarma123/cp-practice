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
    lol cae = 1;
    while (t--)
    {
        lol n;
        cin >> n;
        lol a[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        lol ans = 0;
        lol c[n + 1];
        c[0] = 0;
        for (lol i = 1; i <= n; i++)
        {
            c[i] = c[i - 1] + a[i - 1];
        }
        lol cc[n + 2];
        cc[0] = 0;
        for (lol i = 0; i <= n; i++)
        {
            cc[i + 1] = cc[i] + c[i];
        }
        set<lol> mn;
        mn.insert((n + 1));
        set<pair<lol, lol>> ind;
        for (lol i = 0; i <= n; i++)
        {
            ind.insert({c[i], i});
        }
        auto it = ind.begin();

        while (it != ind.end())
        {
            lol v = (*it).first;
            vector<lol> lazy;
            while (it != ind.end() && (*it).first == v)
            {
                auto j = mn.upper_bound((*it).second);
                lazy.push_back((*it).second);

                lol l = (*it).second;
                lol r = (*j);
                lol q = -c[l] * 1ll * (r - l - 1);
                q += cc[r] - cc[l + 1];

                ans += q;
                it++;
            }
            for (auto e : lazy)
                mn.insert(e);
            lazy.clear();
        }

        cout << "Case #" << cae << ": " << ans << endl;
        cae++;
    }

    return 0;
}