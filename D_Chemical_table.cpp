#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, m, q;
    cin >> n >> m >> q;
    map<lol, vector<lol>> mp;
    while (q--)
    {
        lol r, c;
        cin >> r >> c;
        mp[-r].push_back(c);
        mp[c].push_back(-r);
    }
    set<lol> vis;
    lol ans = 0;

    lol c = 0;
    for (lol i = -n; i <= m; i++)
    {
        if (i == 0)
            continue;
        if (!vis.count(i))
        {
            c++;
            queue<lol> q;
            q.push(i);
            vis.insert(i);
            lol sz = 0;
            while (!q.empty())
            {
                lol v = q.front();
                q.pop();
                sz++;
                for (auto e : mp[v])
                {
                    if (!vis.count(e))
                    {
                        vis.insert(e);
                        q.push(e);
                    }
                }
            }
        }
    }
    cout << c - 1;
}