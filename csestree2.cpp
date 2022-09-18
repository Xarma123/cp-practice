#include <bits/stdc++.h>
#define lol long long
using namespace std;
lol h(map<lol, vector<lol>> &tree, lol x, lol p)
{

    lol s = LONG_LONG_MIN;
    for (lol i = 0; i < tree[x].size(); i++)
    {
        if (tree[x][i] != p)
        {
            s = max(s, h(tree, tree[x][i], x));
        }
    }
    if (s == LONG_LONG_MIN)
        return 1;

    return 1 + s;
}
int main()
{
    lol n;
    cin >> n;
    map<lol, vector<lol>> tree;
    for (lol i = 0; i < n - 1; i++)
    {
        lol a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    cout << (h(tree, 1, -1)) / 2;

    return 0;
}