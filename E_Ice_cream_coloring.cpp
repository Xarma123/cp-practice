#include <bits/stdc++.h>
using namespace std;
#define lol long long
vector<lol> s[300005];
vector<lol> tree[300005];
lol col[300005];
lol ans = 1;
bool cmp(lol a, lol b)
{
    return col[a] < col[b];
}
void dfs(lol c, lol pr)
{
    lol cur = ans;
    sort(s[c].begin(), s[c].end(), cmp);
    lol p = (long long)s[c].size() - 1;
    for (auto e : s[c])
    {
        if (col[e])
        {
            continue;
        }
        while (p >= 0 && cur == col[s[c][p]])
        {
            cur--;
            p--;
        }
        col[e] = cur;
        cur--;
    }
    for (auto e : tree[c])
    {
        if (e != pr)
        {
            dfs(e, c);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, m;
    cin >> n >> m;
    for (lol i = 1; i <= n; i++)
    {
        lol c;
        cin >> c;
        ans = max(ans, c);
        while (c--)
        {
            lol v;
            cin >> v;
            s[i].push_back(v);
        }
    }
    for (lol i = 2; i <= n; i++)
    {
        lol a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    dfs(1, -1);
    cout << ans << '\n';
    for (lol i = 1; i <= m; i++)
    {
        cout << max(col[i],1ll) << " ";
    }

    return 0;
}
