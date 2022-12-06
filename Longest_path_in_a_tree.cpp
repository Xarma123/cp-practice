#include <bits/stdc++.h>
#define lol long long
using namespace std;
lol n;
map<lol, vector<lol>> mp;
lol ans = 0;
lol dfs(lol c, lol p)
{
    lol f = 0, s = 0;
    lol q = 0;
    for (auto e : mp[c])
    {
        if (e != p)
        {
            q++;
            lol v = dfs(e, c);
            ans = max(ans, v);
            if (f < v)
            {
                s = f;
                f = v;
            }
            else if (s < v)
            {
                s = v;
            }
        }
    }
    if (q >= 2)
        ans = max(ans, 1 + s + f);

    return f + 1;
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
        mp[a].push_back(b);
        mp[b].push_back(a);
    }
    ans = max(ans, dfs(1, -1));
    cout << ans - 1;
    return 0;
}