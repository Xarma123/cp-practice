#include <bits/stdc++.h>
using namespace std;
#define lol long long
lol n, m;
map<lol, vector<lol>> mp;

lol solve(vector<lol> ans)
{
    vector<lol> d;
    for (auto e : mp[ans[0]])
        d.push_back(e);
    lol ans1 = m - mp[ans[0]].size();
    lol add = 0;
    for (lol i = 1; i < ans.size(); i++)
    {
        vector<lol> x = mp[ans[i]];
        set<lol> y;
        for (auto e : d)
            y.insert(e);
        for (auto e : x)
            y.insert(e);
        add = max(add, (long long)y.size() - (long long)x.size());
    }
    ans1 += add;
    return ans1;
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    vector<lol> edg;
    for (lol i = 0; i < m; i++)
    {
        lol x, y;
        cin >> x >> y;
        mp[x].push_back(y);
        mp[y].push_back(x);
    }
    if (n <= 6ll)
        cout << m;
    else
    {
        vector<lol> ans;
        for (lol i = 1; i <= n; i++)
        {
            ans.push_back(i);
        }
        lol x = LONG_LONG_MIN;
        for (lol i = 0; i < n; i++)
        {
            swap(ans[0], ans[i]);
            x = max(x, solve(ans));
        }
        cout << x;
    }
}