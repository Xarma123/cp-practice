#include <bits/stdc++.h>
#define lol long long
using namespace std;
stack<lol> st;
lol a[200005];
void dfs(lol s, map<lol, vector<lol>> &mp, bool visit[])
{
    visit[s] = true;

    for (lol i = 0; i < mp[s].size(); i++)
    {
        if (!visit[mp[s][i]])
        {
            dfs(mp[s][i], mp, visit);
        }
    }

    st.push(s);
}
lol dfs1(lol s, map<lol, vector<lol>> &mp, bool visit[])
{
    visit[s] = true;
    lol v = 0;
    for (lol i = 0; i < mp[s].size(); i++)
    {
        if (!visit[mp[s][i]])
        {
            v = max(v, dfs1(mp[s][i], mp, visit));
        }
    }
    return v + a[s];
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, m;
    cin >> n >> m;

    for (lol i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    map<lol, vector<lol>> mp;
    while (m--)
    {
        lol a, b;
        cin >> a >> b;
        mp[a].push_back(b);
    }
    bool visit[n + 1];

    for (lol i = 0; i <= n; i++)
    {
        visit[i] = false;
    }
    for (lol i = 1; i <= n; i++)
    {
        if (!visit[i])
        {
            dfs(i, mp, visit);
        }
    }
    for (lol i = 0; i <= n; i++)
    {
        visit[i] = false;
    }
    lol ans = LONG_LONG_MIN;
    while (!st.empty())
    {

        lol x = st.top();

        if (!visit[x])
        {
            ans = max(ans, dfs1(x, mp, visit));
        }
        st.pop();
    } 
    cout<<ans;

    return 0;
}