#include <bits/stdc++.h>
using namespace std;
#define lol long long
bool cmp(pair<lol, vector<lol>> a, pair<lol, vector<lol>> b)
{
    return (a.second.size() < b.second.size());
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol t;
    cin >> t;
    while (t--)
    {
        lol n;
        cin >> n;
        vector<lol> pf;
        for (lol i = 0; i * 1ll * i <= (long long)1e6; i++)
            pf.push_back((i * 1ll * i));
        vector<lol> mp[n];
        vector<lol> q[n];
        for (lol i = 0; i < n; i++)
        {
            for (auto e : pf)
            {
                if (e - i >= 0 && e - i < n)
                {
                    mp[e - i].push_back(i);
                    q[i].push_back(e - i);
                }
            }
        }
        vector<pair<lol, vector<lol>>> v;
        for (lol i = 0; i < n; i++)
        {
            pair<lol, vector<lol>> p;
            p.first = i;
            p.second = mp[i];
            v.push_back(p);
        }

        sort(v.begin(), v.end(), cmp);
     
        lol ans[n];
        memset(ans, -1, sizeof(ans));
        for (lol i = 0; i < v.size(); i++)
        {
            for (lol j = 0; j < v[i].second.size(); j++)
            {
                if (ans[v[i].second[j]] == -1)
                {
                    ans[v[i].second[j]] = v[i].first;
                    break;
                }
            }
        }
        lol i;
        for (i = 0; i < n; i++)
        {
            if (ans[i] == -1)
            {
                break;
            }
        }
        if (i < n)
            cout << ans[i] << '\n';
        else
        {
            for (i = 0; i < n; i++)
            {
                cout << ans[i] << " ";
            }
            cout << '\n';
        }
    }
}