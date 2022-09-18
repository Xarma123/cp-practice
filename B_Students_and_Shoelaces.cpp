#include <bits/stdc++.h>
#define lol long long
using namespace std;
vector<lol> g[105];
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, m;
    cin >> n >> m;
    map<lol, lol> d;
    while (m--)
    {
        lol a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
        d[a]++;
        d[b]++;
    }
    queue<lol> q;
    lol ans = 0;
    for (lol i = 1; i <= n; i++)
    {
        if (d[i] == 1)
        {

            q.push(i);
            if (ans == 0)
                ans++;
        }
    }
    while (!q.empty())
    {
        lol c = q.size();
        bool wow = false;
        set<lol> vi;
        while (c--)
        {
            lol t = q.front();
            q.pop();
            for (auto e : g[t])
            {
                d[e]--;
                if (d[e] == 1)
                    vi.insert(e);
            }
        }
        for (auto i : vi)
        {
            if (d[i] == 1)
            {

                q.push(i);
                wow = true;
            }
        }
        if (wow)
            ans++;
    }
    cout << ans;

    return 0;
}