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
    set<char> x;
    string q = "IEHOVA";
    x.insert('#');
    for (auto e : q)
        x.insert(e);
    lol n, m;
    while (t--)
    {
        cin >> n >> m;
        map<pair<lol, lol>, pair<lol, lol>> parent;
        string a[n];
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        queue<pair<lol, lol>> q;
        for (lol i = 0; i < m; i++)
        {
            if (a[n - 1][i] == '@')
            {
                q.push({n - 1, i});
                break;
            }
        }
        vis[q.front().first][q.front().second] = true;
        while (!q.empty())
        {
            pair<lol, lol> cur = q.front();
            q.pop();
            // cout << cur.first << " " << cur.second << endl;
            if (cur.first - 1 >= 0 && !vis[cur.first - 1][cur.second] && x.count(a[cur.first - 1][cur.second]))
            {
                parent[{cur.first - 1, cur.second}] = cur;
                vis[cur.first - 1][cur.second] = true;
                q.push({cur.first - 1, cur.second});
            }
            if (cur.second - 1 >= 0 && !vis[cur.first][cur.second - 1] && x.count(a[cur.first][cur.second - 1]))
            {
                parent[{cur.first, cur.second - 1}] = cur;
                vis[cur.first][cur.second - 1] = true;
                q.push({cur.first, cur.second - 1});
            }
            if (cur.second + 1 < m && !vis[cur.first][cur.second + 1] && x.count(a[cur.first][cur.second + 1]))
            {
                parent[{cur.first, cur.second + 1}] = cur;
                vis[cur.first][cur.second + 1] = true;
                q.push({cur.first, cur.second + 1});
            }
        }

        vector<string> ans;
        for (lol i = 0; i < n; i++)
        {
            if (a[0][i] == '#')
            {
                char c = '#';
                lol x = 0, y = i;
                while (c != '@')
                {
                    pair<lol, lol> q = parent[{x, y}];
                    if (q.first != x)
                    {
                        ans.push_back("forth");
                    }
                    else if (q.second > y)
                    {
                        ans.push_back("left");
                    }
                    else
                        ans.push_back("right");
                    x = q.first;
                    y = q.second;
                    c = a[x][y];
                    // cout << ans.back() << " ";
                }

                break;
            }
        }
        while (ans.size())
        {
            cout << ans.back() << " ";
            ans.pop_back();
        }
        cout << endl;
    }

    return 0;
}