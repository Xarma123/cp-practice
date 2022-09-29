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
        lol n, k;
        cin >> n >> k;
        map<lol, vector<lol>> tree;
        for (lol i = 0; i < n - 1; i++)
        {
            lol v;
            cin >> v;

            tree[i + 2].push_back(v);
            tree[v].push_back(i + 2);
        }
        bool vis[n + 1];
        memset(vis, false, sizeof(vis));
        map<lol, lol> lev;
        lol d = 0;
        queue<lol> q;
        q.push(1);
        vis[1] = true;
        while (!q.empty())
        {
            lev[d] = q.size();
            lol c = q.size();
            while (c--)
            {
                lol top = q.front();
                q.pop();
                for (auto e : tree[top])
                {
                    if (!vis[e])
                    {
                        vis[e] = true;
                        q.push(e);
                    }
                }
            }
            d--;
        }

        lol tot = 0;
        lol ans;
        for (auto e : lev)
        {

            if (tot + e.second > k || e.first == -1)
            {

                ans = -e.first;
                break;
            }
            else
            {
                tot += e.second;
            }
        }
        cout << max(ans << endl;
    }

    return 0;
}