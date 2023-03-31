#include <bits/stdc++.h>
#define lol long long
using namespace std;
class dsu
{
public:
    vector<lol> sz;
    vector<lol> par;
    dsu(lol n)
    {
        sz.assign(n + 1, 1);
        par.assign(n + 1, 0);
        for (lol i = 0; i <= n; i++)
        {
            par[i] = i;
        }
    }
    void reset()
    {
        for (lol i = 0; i < sz.size(); i++)
        {
            sz[i] = 1;
        }

        for (lol i = 0; i < par.size(); i++)
        {
            par[i] = i;
        }
    }
    lol find(lol a)
    {
        if (par[a] == a)
            return a;
        return par[a] = find(par[a]);
    }
    bool same(lol x, lol y)
    {
        return (find(x) == find(y));
    }
    void merge(lol x, lol y)
    {
        if (same(x, y))
            return;
        x = find(x);
        y = find(y);
        if (sz[x] <= sz[y])
        {
            par[x] = y;
            sz[y] += sz[x];
        }
        else
        {
            par[y] = x;
            sz[x] += sz[y];
        }
    }
};
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol t;
    cin >> t;
    while (t--)
    {
        lol n, m;
        cin >> n >> m;
        vector<pair<lol, lol>> v;
        string s = "";
        for (lol i = 0; i < m; i++)
        {
            s.push_back('1');
            lol a, b;
            cin >> a >> b;
            v.push_back(make_pair(a, b));
        }
        dsu a(n);
        for (lol i = 0; i < m; i++)
        {
            if (a.same(v[i].first, v[i].second))
                s[i] = '0';
            else
                a.merge(v[i].first, v[i].second);
        }
        a.reset();
        lol i;
        lol qq;
        for (i = 0; i < m; i++)
        {
            if (s[i] == '0')
            {
                if (a.same(v[i].first, v[i].second))
                {
                    qq = i;
                    s[i] = '1';
                    break;
                }
                a.merge(v[i].first, v[i].second);
            }
        }
        if (i == m)
            cout << s << '\n';
        else
        {
         
            a.reset();
            a.merge(v[qq].first, v[qq].second);
            for (lol i = 0; i < m; i++)
            {
                if (s[i] == '0')
                    continue;
                if (i == qq)
                    continue;
                if (a.same(v[i].first, v[i].second))
                    s[i] = '0';
                else
                    a.merge(v[i].first, v[i].second);
            }
            cout << s << '\n';
        }
    }

    return 0;
}