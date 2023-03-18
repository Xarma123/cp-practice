#include <bits/stdc++.h>
#define lol long long
using namespace std;
map<lol, vector<lol>> mp;
lol sc[200005];
map<pair<lol, lol>, lol> memo;
lol solve(lol c, lol k)
{
    if (memo.count({c, k}))
        return memo[{c, k}];
    lol v = sc[c] * 1ll * k;
    if (mp[c].size() == 0)
    {

        return v;
    }
    if (k % ((long long)mp[c].size()) == 0)
    {
        for (auto e : mp[c])
        {
            v += solve(e, k / (mp[c].size()));
        }
    }
    else
    {

        vector<lol> q;
        for (auto e : mp[c])
        {
            lol a = solve(e, k / (mp[c].size()));
            lol b = solve(e, (k / (mp[c].size())) + 1);
            q.push_back(b - a);
            v += a;
        }
        sort(q.rbegin(), q.rend());
        lol x = k % ((long long)mp[c].size());
        for (auto e : q)
        {
            if (x > 0)
            {
                v += e;
            }
            else
                break;
            x--;
        }
    }

    return memo[{c, k}] = v;
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
        lol n, k;
        cin >> n >> k;
        mp.clear();
        memo.clear();
        for (lol i = 2; i <= n; i++)
        {
            lol q;
            cin >> q;
            mp[q].push_back(i);
        }
        for (lol i = 1; i <= n; i++)
        {
            cin >> sc[i];
        }

        cout << solve(1, k) << '\n';
    }

    return 0;
}