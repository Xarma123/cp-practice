#include <bits/stdc++.h>
#define lol long long
using namespace std;
bool cat[100005];
lol m;
vector<lol> tree[100005];
lol ans = 0;
void dfs(lol c, lol p, lol mxc, lol cc)
{
    bool f = false;
    if (cat[c])
    {
        cc++;
    }
    else
    {
        cc = 0;
    }
    mxc = max(mxc, cc);

    for (auto e : tree[c])
    {
        if (e != p)
        {
            f = true;
            dfs(e, c, mxc, cc);
        }
    }

    if (!f)
    {

        if (mxc <= m)
        {
            ans++;
        }
    }
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n;
    cin >> n >> m;
    for (lol i = 1; i <= n; i++)
    {
        cin >> cat[i];
    }
    for (lol i = 0; i < n - 1; i++)
    {
        lol a, b;
        cin >> a >> b;

        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    dfs(1, -1, 0, 0);
    cout << ans;

    return 0;
}