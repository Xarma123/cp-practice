#include <bits/stdc++.h>
using namespace std;
#define lol long long
string s;
lol n;
map<lol, vector<lol>> mp;
lol ans;
void dfs(lol c, lol d)
{
    if (mp[c].size() == 0)
    {
        
        ans = min(ans, d);
        return;
    }
    for (auto e : mp[c])
    {
        if (e > 0)
        {
            dfs(e, d + (s[c - 1] != 'R'));
        }
        else
            dfs(-e, d + (s[c - 1] != 'L'));
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        cin >> s;
        mp.clear();
        ans = LONG_LONG_MAX;
        for (lol i = 1; i <= n; i++)
        {
            lol l, r;
            cin >> l >> r;
            if (l)
                mp[i].push_back(-l);
            if (r)
                mp[i].push_back(r);
        }
        dfs(1, 0);
        cout << ans << '\n';
    }

    return 0;
}
