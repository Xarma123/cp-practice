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
        lol n;
        cin >> n;
        lol b[n];
        map<lol, deque<lol>> mp;
        for (lol i = 0; i < n; i++)
        {
            cin >> b[i];
            mp[b[i]].push_back(i);
        }
        bool q = true;
        for (auto e : mp)
        {
            if (e.second.size() % e.first != 0)
                q = false;
        }
        if (q)
        {
            bool vis[n];
            memset(vis, false, sizeof(vis));
            lol ans[n];
            lol g = 1;
            for (lol i = 0; i < n; i++)
            {
                if (!vis[i])
                {
                    lol f = b[i];
                    while (b[i]--)
                    {
                        vis[mp[f].front()] = true;
                        ans[mp[f].front()] = g;
                        mp[f].pop_front();
                    }
                    g++;
                }
            }
            for (lol i = 0; i < n; i++)
            {
                cout << ans[i] << ' ';
            }
            cout << endl;
        }
        else
            cout << -1 << endl;
    }

    return 0;
}