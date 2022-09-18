#include <bits/stdc++.h>
#define lol long long
using namespace std;
vector<lol> tree[200001];
pair<lol, lol> q;

lol ans(lol x, lol p, vector<lol> &a, lol d)
{
    a[x] = max(a[x], d);
    lol c = 0;

    for (lol i = 0; i < tree[x].size(); i++)
    {
        if (tree[x][i] != p)
        {
            c = max(c, ans(tree[x][i], x, a, d + 1));
        }
    }
    if (d >= q.first)
    {
        q.first = d;
        q.second = x;
    }
    a[x] = max(a[x], c);

    return 1 + c;
}
int main()
{
    lol n;
    cin >> n;
    lol N = n;
    n--;
    while (n--)
    {
        lol a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    vector<lol> a(N + 1);
    q.first = 0;
    q.second = 1;
    for (lol i = 1; i <= N; i++)
    {
        a[i] = LONG_LONG_MIN;
    }
    ans(1, 0, a, 0);

    ans(q.second, 0, a, 0);
    ans(q.second, 0, a, 0);

    for (lol i = 1; i <= N; i++)
    {
        cout << a[i] << " ";
    }

    return 0;
}