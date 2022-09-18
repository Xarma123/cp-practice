#include <bits/stdc++.h>
#define lol long long
using namespace std;
vector<lol> tree[100005];
vector<lol> v(100005, 0);
vector<lol> a(100005, 0);
lol n;
vector<lol> ans;
void dfs(lol c, lol p, lol e, lol o, lol l)
{
   
    if (l % 2 == 0 && e % 2 != 0)
        v[c] = 1 - v[c];
    if (l % 2 != 0 && o % 2 != 0)
        v[c] = 1 - v[c];
    if (v[c] != a[c])
    {
        ans.push_back(c);
        if (l % 2 == 0)
            e++;
        else
            o++;
    }
    for (auto nb : tree[c])
    {
        if (nb != p)
        {
            dfs(nb, c, e, o, l + 1);
        }
    }
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (lol i = 0; i < n - 1; i++)
    {
        lol a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    for (lol i = 1; i <= n; i++)
    {
        cin >> v[i];
    }
    for (lol i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    dfs(1, -1, 0, 0, 0);
    cout << ans.size() << endl;
    for (auto e : ans)
    {
        cout << e << endl;
    }

    return 0;
}