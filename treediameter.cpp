#include <bits/stdc++.h>
#define lol long long
using namespace std;
vector<lol> tree[200001];
lol a = LONG_LONG_MIN;
lol ans(lol x, lol p)
{
    multiset<lol> y;
    for (lol i = 0; i < tree[x].size(); i++)
    {
        if (tree[x][i] != p)
        {
            y.insert(ans(tree[x][i], x));
        }
    }

    lol v = 0, c = 0;
    if (y.size() != 0)
    {
        auto it = y.rbegin();
        v = (*it);
        c = (*it);
        it++;
        if (it != y.rend())
            v += (*it);
    }
    a = max(a, v);
    return c + 1;
}

int main()
{
    lol n;
    cin >> n;
    for (lol i = 0; i < n - 1; i++)
    {
        lol a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    ans(1, 0);
    cout << a;

    return 0;
}