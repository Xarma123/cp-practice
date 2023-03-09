#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol t;
    cin >> t;
    while (t--)
    {
        lol n, m;
        cin >> n >> m;
        map<lol, vector<pair<lol, lol>>> mp;
        for (lol i = 0; i < m; i++)
        {
            lol a, b;
            cin >> a >> b;
            mp[a].push_back({b, i});
            mp[b].push_back({a, i});
        }
        lol ans[m];
        memset(ans, -1, sizeof(ans));
        for (lol i = 1; i <= n; i++)
        {
            if (mp[i].size() < n - 1)
            {
                for (auto x : mp[i])
                {
                    ans[x.second] = 1;
                }
                for (lol j = 0; j < m; j++)
                {
                    if (ans[j] == -1)
                        ans[j] = 2;
                }
                break;
            }
        }
        if (ans[0] == -1)
        {
            cout << 3 << '\n';
            for (auto e : mp[1])
            {
                ans[e.second] = 1;
            }
            ans[mp[1].back().second] = 2;
            for (lol j = 0; j < m; j++)
            {
                if (ans[j] == -1)
                    cout << 3 << " ";
                else
                    cout << ans[j] << " ";
            }
            cout << '\n';
        }
        else
        {
            cout << 2 << '\n';
            for (lol j = 0; j < m; j++)
            {
                cout << ans[j] << " ";
            }
            cout << '\n';
        }
    }

    return 0;
}