#include <bits/stdc++.h>
#define lol long long
using namespace std;
map<lol, vector<vector<lol>>> mp;
lol ans[200005];
void dfs(lol c, lol al, vector<lol> &b)
{
    lol j = upper_bound(b.begin(), b.end(), al) - b.begin();
    ans[c] = j;
    for (auto e : mp[c])
    {
        lol nx = e[0];
        lol a = e[1];
        if (b.size())
            b.push_back(b.back() + e[2]);
        else
            b.push_back(e[2]);
        dfs(nx, al + a, b);
        b.pop_back();
    }
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
        cin >> n;
        mp.clear();
        memset(ans, 0, sizeof(ans));
        for (lol i = 2; i <= n; i++)
        {
            lol a, b, c;
            cin >> a >> b >> c;
            mp[a].push_back({i, b, c});
        }
        vector<lol> x;
        dfs(1, 0, x);
        for (lol i = 2; i <= n; i++)
        {
            cout << ans[i] << " ";
        }
        cout << '\n';
    }

    return 0;
}