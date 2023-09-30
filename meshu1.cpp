#include <bits/stdc++.h>
using namespace std;
#define lol long long
lol parent[100005];
lol sz[100005];
lol mx[100005];
lol ans = 0;
lol find(lol a)
{
    if (parent[a] == a)
        return a;
    return parent[a] = find(parent[a]);
}
void unio(lol a, lol b)
{
    a = find(a);

    b = find(b);

    if (a == b)
        return;
    ans -= min(mx[a], mx[b]);
    if (sz[a] > sz[b])
        swap(a, b);
    sz[b] += sz[a];
    mx[b] = max(mx[a], mx[b]);
    parent[a] = b;
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n;
    cin >> n;
    lol m;
    cin >> m;
    vector<lol> from(m), to(m);
    for (lol i = 0; i < m; i++)
    {
        cin >> from[i];
    }
    for (lol i = 0; i < m; i++)
    {
        cin >> to[i];
    }

    ans = (n * 1ll * (n + 1) / 2ll);
    for (lol i = 1; i <= n; i++)
    {
        parent[i] = i;
        sz[i] = 1;
        mx[i] = i;
    }
    vector<lol> f;
    for (lol i = 0; i < m; i++)
    {
        unio(from[i], to[i]);
        f.push_back(ans);
    }
    for (auto e : f)
        cout << e << " ";
}