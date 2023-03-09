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
    lol a[n];
    map<lol, lol> ind;
    set<lol> x;
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
        ind[a[i]] = i + 1;
        x.insert(a[i]);
    }
    lol s, t;
    cin >> s >> t;
    if (s == t)
    {
        cout << 1 << '\n';
        cout << s;
    }
    else if (__gcd(a[s - 1], a[t - 1]) != 1)
    {
        cout << 2 << '\n';
        cout << s << ' ' << t << '\n';
    }
    else if (a[s - 1] == 1 || a[t - 1] == 1)
    {
        cout << -1;
    }
    else
    {
        bool p[300005];
        memset(p, true, sizeof(p));
        p[1] = false;
        vector<lol> v;
        for (lol i = 2; i < 300005; i++)
        {
            if (p[i])
            {
                v.push_back(i);
                for (lol j = i * 1ll * i; j < 300005; j += i)
                {
                    p[j] = false;
                }
            }
        }
        map<lol, vector<lol>> mp;
        for (auto e : v)
        {
            for (lol j = e; j <= (*x.rbegin()); j += e)
            {
                if (x.count(j))
                {
                    mp[j].push_back(-e);
                    mp[-e].push_back(j);
                }
            }
        }
        queue<lol> q;
        set<lol> vis;
        map<lol, lol> par;
        q.push(a[s - 1]);
        vis.insert(a[s - 1]);
        while (!q.empty())
        {
            lol x = q.front();
            q.pop();
            for (auto e : mp[x])
            {
                if (!vis.count(e))
                {
                    vis.insert(e);
                    par[e] = x;
                    q.push(e);
                }
            }
        }
        if (!vis.count(a[t - 1]))
            cout << -1 << endl;
        else
        {
            vector<lol> ans;
            ans.push_back(t);
            lol c = a[t - 1];
            while (c != a[s - 1])
            {
                c = par[c];
                if (c > 0)
                {
                    ans.push_back(ind[c]);
                }
            }
            cout << ans.size() << endl;
            ans.pop_back();
            cout << s << " ";
            while (ans.size() > 0)
            {
                cout << ans.back() << " ";
                ans.pop_back();
            }
        }
    }

    return 0;
}