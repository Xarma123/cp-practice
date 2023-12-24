#include <bits/stdc++.h>
using namespace std;
#define lol long long
vector<lol> tree[200005];
lol sz[200005];
void dfs(lol c)
{
    sz[c] = 1;
    for (auto e : tree[c])
    {
        dfs(e);
        sz[c] += sz[e];
    }
}

lol dfs(lol c, lol k)
{
    lol tot = 0;
    lol mx = -1;
    for (auto e : tree[c])
    {
        tot += sz[e];
        if (mx == -1 || sz[mx] < sz[e])
            mx = e;
    }
    if (mx == -1)
        return 0;
    if (sz[mx] - k <= tot - sz[mx])
    {
        return ((tot-k) / 2ll);
    }

    lol ex = tot - sz[mx];
    return ex + dfs(mx, max(0ll, k + ex - 1));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol t;
    cin >> t;
    while (t--)
    {
        lol n;
        cin >> n;
        for (lol i = 0; i <= n; i++)
        {
            tree[i].clear();
        }

        for (lol i = 2; i <= n; i++)
        {
            lol c;
            cin >> c;
            tree[c].push_back(i);
        }
        dfs(1);
        cout << dfs(1, 0) << '\n';
    }

    return 0;
}
