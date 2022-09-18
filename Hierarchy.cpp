#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, k;
    cin >> n >> k;
    map<lol, vector<lol>> mp;
    map<lol, lol> ind;
    for (lol i = 1; i <= k; i++)
    {

        lol c;
        cin >> c;
        while (c--)
        {
            lol a;
            cin >> a;
            mp[i].push_back(a);
            ind[a]++;
        }
    }
    queue<lol> q;
    for (lol i = 1; i <= n; i++)
    {
        if (ind[i] == 0)
            q.push(i);
    }
    vector<lol> top;
    while (!q.empty())
    {
        top.push_back(q.front());
        q.pop();
        for (auto e : mp[top.back()])
        {
            ind[e]--;
            if (ind[e] == 0)
            {
                q.push(e);
            }
        }
    }
    lol ans[n + 1];
    for (lol i = 0; i < n; i++)
    {
        if (i == 0)
            ans[top[i]] = 0;
        else
            ans[top[i]] = top[i - 1];
    }
    for (lol i = 1; i <= n; i++)
    {
        cout << ans[i] << endl;
    }

    return 0;
}