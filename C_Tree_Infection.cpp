#include <bits/stdc++.h>
#define lol long long
using namespace std;
lol q[300001];
void dfs(lol src, map<lol, vector<lol>> mp, bool visit[], lol lvl)
{
    visit[src] = true;
    q[lvl]++;
    for (lol i = 0; i < mp[src].size(); i++)
    {
        if (!visit[mp[src][i]])
        {
            dfs(mp[src][i], mp, visit, lvl + 1);
        }
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
        map<lol, vector<lol>> mp;
        for (lol i = 2; i <= n; i++)
        {
            lol k;
            cin >> k;
            mp[k].push_back(i);
        }
        bool visited[n + 1];
        for (lol i = 0; i <= n; i++)
        {
            visited[i] = false;
        }

        dfs(1, mp, visited, 1);

        vector<lol> v;
        for (auto i = 0; i < 300001; i++)
        {
            if (q[i] != 0)
                v.push_back(q[i]);
        }
        sort(v.rbegin(), v.rend());
        lol ans = v.size();
        for (lol i = 0; i < v.size(); i++)
        {
            v[i] -= v.size() - i;
        }
        sort(v.rbegin(), v.rend());
        while (v.back() <= 0)
        {
            v.pop_back();
            if (v.size() == 0)
                break;
        }
        if (v.size() == 0)
            cout << ans << endl;
        else
        {

            lol s = 0;
            lol e = v[0];
            while (s != e - 1)
            {
                lol m = (s + e) / 2;

                lol ex = 0;
                for (lol i = 0; i < v.size(); i++)
                {
                    if (v[i] >= m)
                    {
                        ex += v[i] - m;
                    }
                }
                if (ex <= m)
                {
                    e = m;
                }
                else
                    s = m;
            }
            cout << ans + e << '\n';
        }
        memset(q, 0, sizeof(q));
    }

    return 0;
}