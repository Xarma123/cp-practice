#include <bits/stdc++.h>
using namespace std;
#define lol long long
lol a[40], b[40];
lol n;
map<lol, lol> l, r;
void solve(lol i, lol j, lol v, lol p)
{
    if (i > j)
    {
        l[p] = max(l[p], v);
        return;
    }
    solve(i + 1, j, v + b[i], p + a[i]);
    solve(i + 1, j, v, p);
}
void solve1(lol i, lol j, lol v, lol p)
{
    if (i > j)
    {
        r[p] = max(r[p], v);
        return;
    }
    solve1(i + 1, j, v + b[i], p + a[i]);
    solve1(i + 1, j, v, p);
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    lol mx;
    cin >> mx;
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (lol i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    solve(0, n / 2, 0, 0);
    solve1(n / 2 + 1, n - 1, 0, 0);
    vector<pair<lol, lol>> lf, rt;
    lol ans = 0;
    for (auto e : l)
    {
        if (e.first <= mx)
        {
            lf.push_back(e);
            ans = max(ans, e.second);
        }
    }
    for (auto e : r)
    {
        if (e.first <= mx)
        {
            rt.push_back(e);
            ans = max(ans, e.second);
        }
    }
    sort(lf.begin(), lf.end());
    sort(rt.begin(), rt.end());
   
   
 
    lol p[rt.size()];
    for (lol i = 0; i < rt.size(); i++)
    {
        if (i == 0)
        {
            p[i] = rt[i].second;
        }
        else
        {
            p[i] = p[i - 1];
            p[i] = max(p[i], rt[i].second);
        }
    }

    for (lol i = 0; i < lf.size(); i++)
    {
        lol s = -1, e = rt.size();
        while (s != e - 1)
        {
            lol m = (s + e) / 2ll;
            if (m == -1)
            {
                s = m;
            }
            else if (m == rt.size())
            {
                e = m;
            }
            else if (rt[m].first <= mx - lf[i].first)
            {
                s = m;
            }
            else
                e = m;
        }
        if (s != -1)
        {
            ans = max(ans, lf[i].second + p[s]);
        }
        else
            ans = max(ans, lf[i].first);
    }
    cout << ans;
}