#include <bits/stdc++.h>
using namespace std;
#define lol long long
lol h[200005];
bool cmp(pair<lol, lol> a, pair<lol, lol> b)
{
    return (max(h[a.second], h[a.first]) < max(h[b.second], h[b.first]));
}
bool cmp1(vector<lol> a, vector<lol> b)
{
    return ((h[a[0]] + a[2]) < (h[b[0]] + b[2]));
}
lol p[200005];
lol sz[200005];
lol find(lol a)
{
    if (p[a] == a)
        return a;
    return p[a] = find(p[a]);
}
void unio(lol a, lol b)
{
    a = find(a);
    b = find(b);
    if (a == b)
        return;
    if (sz[a] < sz[b])
    {
        p[a] = b;
        sz[b] += sz[a];
    }
    else
    {
        p[b] = a;
        sz[a] += sz[b];
    }
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
        lol n, m;
        cin >> n >> m;

        for (lol i = 1; i <= n; i++)
        {
            cin >> h[i];
        }
        vector<pair<lol, lol>> v;
        for (lol i = 0; i < m; i++)
        {
            lol a, b;
            cin >> a >> b;
            v.push_back({a, b});
        }
        sort(v.begin(), v.end(), cmp);
       

        for (lol i = 1; i <= n; i++)
        {
            p[i] = i;
            sz[i] = 1;
        }
        lol q;
        cin >> q;

        vector<vector<lol>> query;
        for (lol i = 0; i < q; i++)
        {
            lol a, b, e;
            cin >> a >> b >> e;
            query.push_back({a, b, e, i});
        }
        sort(query.begin(), query.end(), cmp1);
        bool ans[q];
        lol j = 0;
        for (lol i = 0; i < q; i++)
        {
            while (j < v.size() && max(h[v[j].first], h[v[j].second]) <= h[query[i][0]] + query[i][2])
            {
                unio(v[j].first, v[j].second);
                j++;
            }
            ans[query[i][3]] = (find(query[i][0]) == find(query[i][1]));
        }
        for (lol i = 0; i < q; i++)
        {
            if (ans[i])
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }
}