#include <bits/stdc++.h>
#define lol long long
using namespace std;
map<lol, vector<lol>> mp;
lol dfsx(lol c, lol p, lol d[], bool a[], lol l)
{

    d[c] = l;
    lol v = 0;
    for (auto e : mp[c])
    {
        if (e != p)
        {

            v += dfsx(e, c, d, a, l + 1);
        }
    }
    if (v > 0)
        return v + 1;
    else if (a[c])
        return 1;
    else
        return 0;
}
void dfs(lol c, lol p, lol d[], lol l)
{
    d[c] = l;
    for (auto e : mp[c])
    {
        if (e != p)
        {
            dfs(e, c, d, l + 1);
        }
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
        lol n, k;
        mp.clear();
        cin >> n >> k;
        lol x, y;
        cin >> x >> y;
        bool a[n + 1];
        memset(a, false, sizeof(a));

        for (lol i = 0; i < k; i++)
        {
            lol v;
            cin >> v;
            a[v] = true;
        }
        for (lol i = 0; i < n - 1; i++)
        {
            lol q, w;
            cin >> q >> w;
            mp[q].push_back(w);
            mp[w].push_back(q);
        }
        lol dx[n + 1];
        lol dy[n + 1];
        lol tot = 2ll * (dfsx(x, -1, dx, a, 0) - 1);
     
        dfs(y, -1, dy, 0);
        lol ans = LONG_LONG_MAX;
        a[x] = true;
        for (lol i = 1; i <= n; i++)
        {
            if (a[i])
            {
                ans = min(ans, tot - dx[i] + dy[i]);
            }
        }
        cout << ans << '\n';
    }

    return 0;
}