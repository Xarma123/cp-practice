#include <bits/stdc++.h>
#define lol long long
using namespace std;
vector<lol> mp[100001];
lol ind[100001];
lol n, m;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    while (m--)
    {
        lol a, b;
        cin >> a >> b;
        mp[a].push_back(b);
        ind[b]++;
    }
    queue<lol> q;
    for (lol i = 1; i <= n; i++)
    {
        if (ind[i] == 0)
            q.push(i);
    }
    bool f = false;
    lol c[n + 1];
    memset(c, 0, sizeof(c));
    c[1] = 1;
    while (!q.empty())
    {
        lol v = q.front();
        q.pop();
        if (v == 1)
            f = true;
        for (lol i = 0; i < mp[v].size(); i++)
        {
            if (f)
                c[mp[v][i]] = (c[mp[v][i]] + c[v]) % 1000000007;
            ind[mp[v][i]]--;
            if (ind[mp[v][i]] == 0)
                q.push(mp[v][i]);
        }
    } 
    cout<<c[n];

    return 0;
}