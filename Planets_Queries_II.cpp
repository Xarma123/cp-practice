#include <bits/stdc++.h>
#define lol long long
using namespace std;
lol child[200001][31];

vector<lol> cycle;
void dfs(lol src, bool visited[], bool recu[])
{
    visited[src] = true;
    recu[src] = true;
    if (!visited[child[src][0]])
        dfs(child[src][0], visited, recu);
    else if (recu[child[src][0]])
        cycle.push_back(src);
    recu[src] = false;
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, q;
    cin >> n >> q;
    for (lol i = 1; i <= n; i++)
    {
        cin >> child[i][0];
    }
    for (lol d = 1; d < 31; d++)
    {
        for (lol i = 1; i <= n; i++)
        {
            child[i][d] = child[child[i][d - 1]][d - 1];
        }
    }
    bool visited[n + 1];
    bool rec[n + 1];
    memset(visited, false, sizeof(visited));

    memset(rec, false, sizeof(rec));
    for (lol i = 1; i <= n; i++)
        if (!visited[i])
            dfs(1, visited, rec);

    for (lol i = 0; i < cycle.size(); i++)
    {
    }

    while (q--)
    {
        lol a, b;
        cin >> a >> b;
    }

    return 0;
}