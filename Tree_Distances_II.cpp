#include <bits/stdc++.h>
#define lol long long
using namespace std;
vector<lol> tree[200001];
lol ans[200001];
lol y = 0;
lol a(lol x, lol p, lol d)
{
    lol c = 1;
    y += d;

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
void b(lol x, lol p, lol n)
{
    for (lol i = 0; i < tree[x].size(); i++)
    {
        if (tree[x][i] != p)
        {
            ans[tree[x][i]] = ans[x] + n - 2 * ans[tree[x][i]];
            b(tree[x][i], x, n);
        }
    }
}

int main()
{
    lol n;
    cin >> n;
    for (lol i = 1; i < n; i++)
    {
        lol a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    a(1, 0, 0);
    ans[1] = y;
    b(1, 0, n);
    for (lol i = 1; i <= n; i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}