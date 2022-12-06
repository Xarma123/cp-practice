#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol c = 0;
    while (1)
    {
        c++;
        lol n;
        cin >> n;
        if (n == 0)
            break;
        map<string, vector<string>> mp;
        vector<string> q;
        map<string, lol> ind;
        for (lol i = 0; i < n; i++)
        {
            lol v;
            cin >> v;
            string l = "";
            while (v--)
            {
                string s;
                cin >> s;
                q.push_back(s);
                ind[s] = q.size() - 1;
                if (l == "")
                {
                    l = s;
                    continue;
                }
                mp[l].push_back(s);
                l = s;
            }
        }
        cin >> n;
        for (lol i = 0; i < n; i++)
        {
            string a, b;
            cin >> a >> b;
            mp[a].push_back(b);
        }
        lol dp[q.size()][q.size()];

        for (lol i = 0; i < q.size(); i++)
        {
            for (lol j = 0; j < q.size(); j++)
            {
                dp[i][j] = 1e9;
            }
        }
        for (auto e : mp)
        {
            for (auto s : e.second)
            {
                dp[ind[e.first]][ind[s]] = 0;
            }
        }
        vector<pair<lol, lol>> ans;
        for (lol k = 0; k < q.size(); k++)
        {
            for (lol i = 0; i < q.size(); i++)
            {
                for (lol j = 0; j < q.size(); j++)
                {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
                }
            }
        }
        for (lol i = 0; i < q.size(); i++)
        {
            for (lol j = i + 1; j < q.size(); j++)
            {
                if (dp[i][j] == 1e9 && dp[j][i] == 1e9)
                    ans.push_back({i, j});
            }
        }
        if (ans.size() == 0)
            cout << "Case " << c << ", no concurrent events." << endl;
        else
        {
            cout << "Case " << c << ", " << ans.size() << " concurrent events:" << endl;
            cout << "(" << q[ans[0].first] << "," << q[ans[0].second] << ") ";
            if (ans.size() > 1)
                cout << "(" << q[ans[1].first] << "," << q[ans[1].second] << ") ";
            cout << endl;
        }
    }

    return 0;
}