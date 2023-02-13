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
    while (t--)
    {
        lol n, c;
        cin >> n >> c;
        lol a[n];
        multiset<pair<lol, lol>> x;
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
            x.insert({a[i] + i + 1, i});
            x.insert({a[i] + n - i, i});
        }

        set<lol> used;
        vector<lol> v;
        map<lol, lol> mp;
        while (!x.empty())
        {
            pair<lol, lol> q = (*x.begin());
            x.erase(x.begin());
            if (used.count(q.second))
                continue;
            used.insert(q.second);
            v.push_back(q.first);
            mp[q.second] = v.size() - 1;
        }
        for (lol i = 1; i < v.size(); i++)
        {
            v[i] += v[i - 1];
        }
        lol ans = LONG_LONG_MIN;
        for (lol i = 0; i < n; i++)
        {
            lol qc = c;
            if (a[i] + i + 1 <= qc)
            {
                qc -= a[i] + i + 1;
                lol st = -1, e = v.size();
                while (st != e - 1)
                {
                    lol m = (st + e) / 2;
                    if (m == -1)
                        st = m;
                    else if (m == v.size())
                        e = m;
                    else
                    {
                        lol xx = v[m];
                        if (m >= mp[i])
                        {
                            xx -= v[mp[i]];
                            if (mp[i])
                                xx += v[mp[i] - 1];
                        }
                        if (xx <= qc)
                            st = m;
                        else
                            e = m;
                    }
                }
                if (st >= mp[i])
                    ans = max(ans, st + 1);
                else
                    ans = max(ans, st + 2);
            }
        }
        cout << max(ans, 0ll) << '\n';
    }
    return 0;
}
