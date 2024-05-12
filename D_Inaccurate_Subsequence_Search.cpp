#include <bits/stdc++.h>
using namespace std;
#define lol long long
map<lol, vector<lol>> mp;
lol k;
lol ans = 0;
lol dfs(lol c, lol p)
{
    lol tot = 1;
    for (auto e : mp[c])
    {
        if (e != p)
        {
            lol f = dfs(e, c);
            tot += f;
            ans += (f + k - 1) / k;
        }
    }
    return tot;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n;
    cin >> n;
    cin >> k;
    lol a[n - 1];
    lol b[n - 1];
    for (lol i = 0; i < n - 1; i++)
    {
        cin >> a[i];
        cin >> b[i];
        mp[a[i]].push_back(b[i]);
        mp[b[i]].push_back(a[i]);
    }
    dfs(1, -1);
    cout << ans;

    return 0;
}
