#include <bits/stdc++.h>
#define lol long long
using namespace std;
lol mp[200005];
bool visit[200005];
bool recu[200005];
lol dist[200005];
vector<lol> back;
void dfs(lol s)
{
    visit[s] = true;
    recu[s] = true;
    if (mp[s] == 0)
    {
        dist[s] = 0;
    }
    else if (!visit[mp[s]])
    {

        dfs(mp[s]);
        dist[s] = dist[mp[s]] + 1;
    }
    else if (visit[mp[s]])
    {
        if (recu[mp[s]])
        {
            dist[s] = 1;
            back.push_back(mp[s]);
        }
        else
        {
            dist[s] = dist[mp[s]] + 1;
        }
    }
    recu[s] = false;
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n;
    cin >> n;
    for (lol i = 1; i <= n; i++)
    {
        cin >> mp[i];
    }

    memset(visit, false, sizeof(visit));
    memset(recu, false, sizeof(recu));
    for (lol i = 1; i <= n; i++)
    {
        if (!visit[i])
        {
            dfs(i);
        }
        while (back.size())
        {
            lol v = back.back();
            back.pop_back();
            lol g = dist[v];
            lol c = mp[v];
            while (c != v)
            {
                dist[c] = g;
                c = mp[c];
            }
        }
    }
    for (lol i = 1; i <= n; i++)
    {
        cout << dist[i] << " ";
    }

    return 0;
}