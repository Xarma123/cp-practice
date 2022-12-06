#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol t;
    cin >> t;
    while (t--)
    {
        lol a, b, c;
        cin >> a >> b >> c;
        queue<vector<lol>> q;
        q.push({0, 0, 0});
        set<pair<lol, lol>> vis;
        lol ans = -1;
        while (!q.empty())
        {
            vector<lol> e = q.front();
            q.pop();
            if (vis.count({e[0], e[1]}))
                continue;
            vis.insert({e[0], e[1]});
            if (e[0] == c || e[1] == c)
            {
                ans = e[2];
                break;
            }
            if (!vis.count({0, e[1]}))
            {

                q.push({0, e[1], e[2] + 1});
            }
            if (!vis.count({e[0], 0}))
            {

                q.push({e[0], 0, e[2] + 1});
            }
            if (!vis.count({a, e[1]}))
            {

                q.push({a, e[1], e[2] + 1});
            }
            if (!vis.count({e[0], b}))
            {

                q.push({e[0], b, e[2] + 1});
            }
            if (!vis.count({max(e[0] + e[1] - b, 0ll), min(b, e[0] + e[1])}))
            {

                q.push({max(e[0] + e[1] - b, 0ll), min(b, e[0] + e[1]), e[2] + 1});
            }
            if (!vis.count({min(a, e[0] + e[1]), max(e[0] + e[1] - a, 0ll)}))
            {

                q.push({min(a, e[0] + e[1]), max(e[0] + e[1] - a, 0ll), e[2] + 1});
            }
        }
        cout << ans << endl;
    }

    return 0;
}