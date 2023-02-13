#include <bits/stdc++.h>
#define lol long long
using namespace std;
map<lol, set<lol>> mp;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n;
    cin >> n;
    for (lol i = 1; i < n; i++)
    {
        lol a, b;
        cin >> a >> b;
        mp[a].insert(b);
        mp[b].insert(a);
    }
    lol a[n];
    bool vis[n + 1];
    memset(vis, false, sizeof(vis));
    for (lol i = 0; i < n; i++)
        cin >> a[i];
    queue<lol> q;
    q.push(1);
    vis[1] = true;
    map<lol, set<lol>> x;
    lol l = 0;
    while (!q.empty())
    {
        lol c = q.size();
        while (c--)
        {
            lol z = q.front();
            q.pop();
            x[l].insert(z);
            for (auto e : mp[z])
            {
                if (!vis[e])
                {
                    vis[e] = true;
                    q.push(e);
                }
            }
        }
        l++;
    }
    l = 0;
    bool ans = true;
    for (lol i = 0; i < n; i++)
    {
        if (x[l].count(a[i]))
        {
            x[l].erase(a[i]);
            if (x[l].size() == 0)
                l++;
        }
        else
        {
            ans = false;
            break;
        }
    }
    l = 0;
    mp[1].insert(0);
    for (lol i = 1; i < n && ans; i++)
    {
        lol j = i + mp[a[l]].size() - 1;
        if (j - 1 >= n)
        {
            ans = false;
            break;
        }
        for (lol k = i; k < j; k++)
        {
            if (!mp[a[l]].count(a[k]))
            {
                ans = false;
                break;
            }
        }
        l++;
        i = j - 1;
    }

    if (ans)
        cout << "Yes";
    else
        cout << "No";

    return 0;
}