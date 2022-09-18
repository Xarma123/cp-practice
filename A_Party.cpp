#include <bits/stdc++.h>
#define lol long long
using namespace std;
lol h(lol root, map<lol, vector<lol>> &mp, bool visited[])
{
    visited[root-1] = true;
    lol c = 0;
    for (lol i = 0; i < mp[root].size(); i++)
    {
        c = max(c, h(mp[root][i], mp, visited));
    }
    return 1 + c;
}
int main()
{
    lol n;
    cin >> n;
    bool visited[n];
    map<lol, vector<lol>> mp;
    for (lol i = 0; i < n; i++)
    {
        visited[i] = false;
        lol t;
        cin >> t;
        if (t != -1)
            mp[t].push_back(i + 1);
    }

    lol ans = 0;
    for (lol i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            ans = max(ans, h(i + 1, mp, visited));
        }
    }
    cout<<ans;

    return 0;
}