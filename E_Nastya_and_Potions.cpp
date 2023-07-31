#include <bits/stdc++.h>
using namespace std;
#define lol long long
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
        lol c[n + 1];
        for (lol i = 1; i <= n; i++)
        {
            cin >> c[i];
        }
        lol p[k];
        set<lol> x;
        map<lol, lol> ind;
        map<lol, vector<lol>> mp;
        map<lol, vector<lol>> baaps;
        for (lol i = 0; i < k; i++)
        {
            cin >> p[i];
            x.insert(p[i]);
            c[p[i]] = 0;
        }
        for (lol i = 0; i < n; i++)
        {
            lol m;
            cin >> m;
            for (lol j = 0; j < m; j++)
            {
                lol in;
                cin >> in;
                if (!x.count(in))
                {
                    ind[i + 1]++;
                    mp[in].push_back(i + 1);
                    baaps[i + 1].push_back(in);
                }
            }
            if (m == 0)
            {
                baaps[i + 1].push_back(-1);
            }
        }
        queue<lol> q;
        for (lol i = 1; i <= n; i++)
        {
            if (ind[i] == 0)
                q.push(i);
        }
        while (!q.empty())
        {
            lol v = q.front();
            q.pop();
            lol cc = 0;
            for (auto e : baaps[v])
            {
                if (e == -1)
                    cc = LONG_LONG_MAX;
                else
                    cc += c[e];
            }
            c[v] = min(c[v], cc);
            for (auto e : mp[v])
            {
                ind[e]--;
                if (ind[e] == 0)
                    q.push(e);
            }
        }
        for (lol i = 1; i <= n; i++)
        {
            cout << c[i] << " ";
        }
        cout << '\n';
    }
}