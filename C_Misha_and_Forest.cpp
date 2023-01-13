#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n;
    cin >> n;
    map<lol, lol> ind;
    map<lol, lol> x;

    for (lol i = 0; i < n; i++)
    {

        cin >> ind[i];
        cin >> x[i];
    }
    queue<lol> q;
    for (lol i = 0; i < n; i++)
    {
        if (ind[i] == 1)
        {
            q.push(i);
        }
    }
    vector<vector<lol>> edg;
    while (!q.empty())
    {
        lol v = q.front();
        q.pop();
        if (ind[v] != 1)
            continue;
        edg.push_back({v, x[v]});
        x[x[v]] ^= v;
        ind[x[v]]--;
        if (ind[x[v]] == 1)
            q.push(x[v]);
    }
    cout << edg.size() << '\n';
    for (auto e : edg)
    {
        cout << e[0] << " " << e[1] << '\n';
    }

    return 0;
}