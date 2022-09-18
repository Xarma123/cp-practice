#include <bits/stdc++.h>
#define lol long long
using namespace std;
vector<lol> tree[200001];
pair<lol, lol> ans(lol x, lol p)
{
    pair<lol, lol> r = make_pair(0, 0);
    vector<pair<lol, lol>> y;
    for (lol i = 0; i < tree[x].size(); i++)
    {
        if (tree[x][i] != p)
        {

            y.push_back(ans(tree[x][i], x));
        }
    }
    if (y.size() == 0)
        return r;

    bool u = false;
    for (lol i = 0; i < y.size(); i++)
    {
        r.second += max(y[i].first, y[i].second);
        if (y[i].second >= y[i].first)
            u = true;
    }
    if (u)
        r.first = r.second + 1;
    else
    {
        for (lol i = 0; i < y.size(); i++)
        {
            r.first = max(r.second - y[i].first + y[i].second + 1, r.first);
        }
    }

    return r;
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
    pair<lol, lol> a = ans(1, 0);
    cout << max(a.first, a.second);

    return 0;
}