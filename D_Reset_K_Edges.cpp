#include <bits/stdc++.h>
#define lol long long
using namespace std;
map<lol, vector<lol>> tree;
lol k;
lol q;
lol h(lol p, lol c)
{
    lol v = 0;
    for (auto e : tree[c])
    {
        if (e != p)
        {
            v = max(v, h(c, e));
        }
    }
    return v + 1;
}
lol dfs(lol p, lol c, lol mn)
{
    lol v = 0;
    for (auto e : tree[c])
    {
        if (e != p)
        {
            v = max(v, dfs(c, e, mn));
        }
    }
    if (v + 1 == mn - 1 && p != 1&&p!=-1)
    {
        q++;
        return 0;
    }
    return v + 1;
}
bool check(lol mn)
{
    q = 0;
    dfs(-1, 1, mn);
   
    return q <= k;
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol t;
    cin >> t;
    while (t--)
    {
        lol n;
        cin >> n >> k;
        tree.clear();
        for (lol i = 0; i < n - 1; i++)
        {
            lol v;
            cin >> v;

            tree[i + 2].push_back(v);
            tree[v].push_back(i + 2);
        }
        lol s = 0, e = h(-1, 1);

        while (s != e - 1)
        {
            lol m = (s + e) / 2;
            if (m <= 1)
            {
                s = m;
            }
            else if (check(m))
            {
                e = m;
            }
            else
                s = m;
           
        }
         cout << e - 1 << endl;
    }

    return 0;
}