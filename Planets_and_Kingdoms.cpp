#include <bits/stdc++.h>
#define lol long long
using namespace std;
stack<lol> st;
lol ans[200005];
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
void dfs1(lol s, map<lol, vector<lol>> &mp, bool visit[], lol k)
{
    visit[s] = true;
    ans[s] = k;
    for (lol i = 0; i < mp[s].size(); i++)
    {
        if (!visit[mp[s][i]])
        {
            dfs1(mp[s][i], mp, visit, k);
        }
    }
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, m;
    cin >> n >> m;
    map<lol, vector<lol>> mp;
    map<lol, vector<lol>> mp1;
    while (m--)
    {
        lol a, b;
        cin >> a >> b;
        mp[a].push_back(b);
        mp1[b].push_back(a);
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
    lol k = 1;
    while (!st.empty())
    {

        lol x = st.top();

        if (!visit[x])
        {
            dfs1(x, mp1, visit, k);
            k++;
        }
        st.pop();
    }
    cout << k - 1 << endl;
    for (lol i = 1; i <= n; i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}