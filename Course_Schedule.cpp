#include <bits/stdc++.h>
#define lol long long
using namespace std;
stack<lol> f;
bool dfs(lol s, map<lol, vector<lol>> &mp, bool visit[], bool rec[])
{
    visit[s] = true;
    rec[s] = true;
    for (lol i = 0; i < mp[s].size(); i++)
    {
        if (!visit[mp[s][i]])
        {
            if (dfs(mp[s][i], mp, visit, rec))
                return true;
        }
        else if (rec[mp[s][i]])
        {
            return true;
        }
    }
    rec[s] = false;
    f.push(s);
    return false;
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, m;
    cin >> n >> m;
    map<lol, vector<lol>> mp;
    while (m--)
    {
        lol a, b;
        cin >> a >> b;
        mp[a].push_back(b);
    }
    bool visit[n + 1];
    bool rec[n + 1];
    for (lol i = 0; i <= n; i++)
    {
        visit[i] = false;
        rec[i] = false;
    }
    bool ans = true;
    for (lol i = 1; i <= n; i++)
    {
        if (!visit[i])
        {
            if (dfs(i, mp, visit, rec))
            {
                ans = false;
                break;
            }
        }
    }
    if (ans)
    {
        while (!f.empty())
        {
            cout << f.top() << " ";
            f.pop();
        }
    }
    else
        cout << "IMPOSSIBLE";

    return 0;
}