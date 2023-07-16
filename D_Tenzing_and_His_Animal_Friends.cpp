#include <bits/stdc++.h>
using namespace std;
#define lol long long

int main()
{
    lol n, m;
    cin >> n >> m;
    map<lol, vector<pair<lol, lol>>> mp;
    while (m--)
    {
        lol a, b, y;
        cin >> a >> b >> y;
        mp[a].push_back({b, y});
        mp[b].push_back({a, y});
    }
    string s(n, '0');
    set<pair<lol, lol>> x;
    x.insert({0, 1});
    lol ans = 0;
    vector<string> q;
    bool f = true;
    while (!x.empty() && f)
    {
        pair<lol, lol> p = *x.begin();
        x.erase(p);
        ans += p.first;
        if (p.first)
            q.push_back(s + " " + to_string(p.first));
        if (p.second == n)
            f = false;
        vector<lol> qq;
        qq.push_back(p.second);
        while (x.size() > 0 && (*x.begin()).first == p.first)
        {
            auto t = *x.begin();
            if (t.second == n)
                f = false;
            x.erase(t);
            qq.push_back(t.second);
        }
        vector<pair<lol, lol>> wx;
        for (auto e : x)
        {
            wx.push_back({e.first - p.first, e.second});
        }
        x.clear();
        for (auto e : wx)
        {
            x.insert(e);
        }
        for (auto ee : qq)
        {

            s[ee - 1] = '1';
        }

        for (auto ee : qq)
        {
            for (auto e : mp[ee])
            {

                if (s[e.first - 1] == '1')
                    continue;

                x.insert({e.second, e.first});
            }
        }
    }
    if (f)
        cout << "inf";
    else
    {
        cout << ans << " " << q.size() << '\n';
        for (auto e : q)
            cout << e << '\n';
    }
}