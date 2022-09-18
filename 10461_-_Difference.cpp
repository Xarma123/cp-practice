#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol c = 1;
    while (1)
    {
        lol v, e;
        cin >> v >> e;
        if (v == e && v == 0)
            break;
        lol time[v + 1];
        for (lol i = 1; i <= v; i++)
        {
            cin >> time[i];
        }
        vector<vector<lol>> gr(v + 1);
        vector<vector<lol>> grr(v + 1);
        while (e--)
        {
            lol x, y;
            cin >> x >> y;
            gr[x].push_back(y);
            grr[y].push_back(x);
        }
        lol q;
        cin >> q;
        cout << "Case #" << c << ":" << endl;
        while (q--)
        {
            lol n;
            cin >> n;
            bool vgr[v + 1];
            memset(vgr, false, sizeof(vgr));
            vgr[n] = true;
            queue<lol> bfs;
            bfs.push(n);
            while (!bfs.empty())
            {
                lol cur = bfs.front();
                bfs.pop();
                for (auto e : gr[cur])
                {
                    if (!vgr[e])
                    {
                        vgr[e] = true;
                        bfs.push(e);
                    }
                }
            }
            bool vgrr[v + 1];
            memset(vgrr, false, sizeof(vgr));
            vgrr[n] = true;
            bfs.push(n);
            while (!bfs.empty())
            {
                lol cur = bfs.front();
                bfs.pop();
                for (auto e : grr[cur])
                {
                    if (!vgrr[e])
                    {
                        vgrr[e] = true;
                        bfs.push(e);
                    }
                }
            }
            lol mx = 0;
            for (lol i = 1; i <= v; i++)
            {
                if (!vgr[i])
                    mx += time[i];
            }
            mx += time[n];
            lol mn = 0;
            for (lol i = 1; i <= v; i++)
            {
                if (vgrr[i])
                    mn += time[i];
            }
            cout << mx - mn << endl;
        }
        c++;
        cout << endl;
    }

    return 0;
}