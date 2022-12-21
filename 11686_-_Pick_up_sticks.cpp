#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    while (1)
    {
        lol n, m;
        cin >> n >> m;
        if (n == 0 && m == 0)
            break;
        map<lol, vector<lol>> mp;
        map<lol, lol> ind;
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
        vector<lol> ans;
        bool f = true;
        while (!q.empty())
        {
            lol e = q.front();
            ans.push_back(e);
            q.pop();
            for (auto x : mp[e])
            {
                if (--ind[x] == 0)
                    q.push(x);
                if (ind[x] < 0)
                    f = false;
            }
        }
        if (ans.size() == n && f)
        {
            for (auto e : ans)
                cout << e << endl;
        }
        else
            cout << "IMPOSSIBLE" << endl;
    }

    return 0;
}