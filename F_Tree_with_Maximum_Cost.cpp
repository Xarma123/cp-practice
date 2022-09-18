#include <bits/stdc++.h>
#define lol long long
using namespace std;
vector<lol> tree[200001];
lol ans[200001];
lol cost[200001];
lol y = 0;
lol a(lol x, lol p, lol d)
{
    lol c = cost[x];
    y += d * 1ll * cost[x];

    for (lol i = 0; i < tree[x].size(); i++)
    {
        if (tree[x][i] != p)
        {
            c +=
                a(tree[x][i], x, d + 1);
        }
    }
    ans[x] = c;
    return c;
}
void b(lol x, lol p, lol s)
{
    for (lol i = 0; i < tree[x].size(); i++)
    {
        if (tree[x][i] != p)
        {
            ans[tree[x][i]] = ans[x] + s - 2 * ans[tree[x][i]];
            b(tree[x][i], x, s);
        }
    }
}

int main()
{
    lol n;
    cin >> n;
    lol s = 0;
    for (lol i = 1; i <= n; i++)
    {
        lol a;
        cin >> a;
        cost[i] = a;
        s += a;
    }

    for (lol i = 1; i < n; i++)
    {
        lol a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    a(1, 0, 0);
    ans[1] = y;
    b(1, 0, s);
    lol ansf = LONG_LONG_MIN;
    for (lol i = 1; i <= n; i++)
    {
        ansf = max(ansf, ans[i]);
    }
    cout << ansf;

    return 0;
}