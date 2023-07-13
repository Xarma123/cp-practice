#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        lol n, m;
        cin >> n >> m;
        string s;
        cin >> s;
        vector<pair<lol, pair<string, string>>> v(m);
        for (lol i = 0; i < m; i++)
        {
            cin >> v[i].first >> v[i].second.first >> v[i].second.second;
        }
        map<string, lol> d;
        set<pair<lol, string>> x;
        x.insert({0, s});
        while (!x.empty())
        {
            pair<lol, string> tp = (*x.begin());
            x.erase(x.begin());

            if ((d.count(tp.second) > 0) && d[tp.second] <= tp.first)
                continue;

            d[tp.second] = tp.first;

            for (lol i = 0; i < m; i++)
            {
                string q = tp.second;
                for (lol j = 0; j < 10; j++)
                {
                    if (q[j] == '1' && v[i].second.first[j] == '1')
                        q[j] = '0';
                    if (q[j] == '0' && v[i].second.second[j] == '1')
                        q[j] = '1';
                }
                if (d.count(q))
                {
                    if (d[q] > v[i].first + d[tp.second])
                    {
                        x.insert({v[i].first + d[tp.second], q});
                    }
                }
                else
                {
                    x.insert({v[i].first + d[tp.second], q});
                }
            }
        }
        for (lol i = 0; i < 10; i++)
        {
            s[i] = '0';
        }
        if (d.count(s))
            cout << d[s] << '\n';
        else
            cout << -1 << '\n';
    }
}