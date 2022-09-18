#include <bits/stdc++.h>
#define lol long long
using namespace std;
lol n, m;
void call(pair<lol, lol> src, vector<vector<bool>> visited, vector<vector<pair<lol, lol>>> &parent, lol mode, vector<vector<lol>> &tm, vector<vector<lol>> &ta, vector<pair<lol, lol>> &mo)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    if (mode)
    {
        queue<pair<pair<lol, lol>, lol>> bfs;
        bfs.push(make_pair(src, 0));
        visited[src.first][src.second] = true;
        while (!bfs.empty())
        {
            pair<pair<lol, lol>, lol> x = bfs.front();

            ta[x.first.first][x.first.second] = min(x.second, ta[x.first.first][x.first.second]);
            bfs.pop();
            if (x.first.first + 1 < n)
            {
                if (!visited[x.first.first + 1][x.first.second])
                {
                    visited[x.first.first + 1][x.first.second] = true;
                    parent[x.first.first + 1][x.first.second] = x.first;
                    bfs.push(make_pair(make_pair(x.first.first + 1, x.first.second), x.second + 1));
                }
            }
            if (x.first.first - 1 >= 0)
            {
                if (!visited[x.first.first - 1][x.first.second])
                {
                    visited[x.first.first - 1][x.first.second] = true;
                    parent[x.first.first - 1][x.first.second] = x.first;
                    bfs.push(make_pair(make_pair(x.first.first - 1, x.first.second), x.second + 1));
                }
            }
            if (x.first.second - 1 >= 0)
            {
                if (!visited[x.first.first][x.first.second - 1])
                {
                    visited[x.first.first][x.first.second - 1] = true;
                    parent[x.first.first][x.first.second - 1] = x.first;
                    bfs.push(make_pair(make_pair(x.first.first, x.first.second - 1), x.second + 1));
                }
            }
            if (x.first.second + 1 < m)
            {
                if (!visited[x.first.first][x.first.second + 1])
                {
                    visited[x.first.first][x.first.second + 1] = true;
                    parent[x.first.first][x.first.second + 1] = x.first;
                    bfs.push(make_pair(make_pair(x.first.first, x.first.second + 1), x.second + 1));
                }
            }
        }
    }
    else
    {
        queue<pair<pair<lol, lol>, lol>> bfs;
        for (lol i = 0; i < mo.size(); i++)
        {
            bfs.push(make_pair(mo[i], 0));
            visited[mo[i].first][mo[i].second] = true;
        }

        while (!bfs.empty())
        {
            pair<pair<lol, lol>, lol> x = bfs.front();
            bfs.pop();
            if (tm[x.first.first][x.first.second] == 0)
                continue;
            tm[x.first.first][x.first.second] = min(x.second, tm[x.first.first][x.first.second]);

            if (x.first.first + 1 < n)
            {
                if (!visited[x.first.first + 1][x.first.second])
                {
                    visited[x.first.first + 1][x.first.second] = true;

                    bfs.push(make_pair(make_pair(x.first.first + 1, x.first.second), x.second + 1));
                }
            }
            if (x.first.first - 1 >= 0)
            {
                if (!visited[x.first.first - 1][x.first.second])
                {
                    visited[x.first.first - 1][x.first.second] = true;

                    bfs.push(make_pair(make_pair(x.first.first - 1, x.first.second), x.second + 1));
                }
            }
            if (x.first.second - 1 >= 0)
            {
                if (!visited[x.first.first][x.first.second - 1])
                {
                    visited[x.first.first][x.first.second - 1] = true;

                    bfs.push(make_pair(make_pair(x.first.first, x.first.second - 1), x.second + 1));
                }
            }
            if (x.first.second + 1 < m)
            {
                if (!visited[x.first.first][x.first.second + 1])
                {
                    visited[x.first.first][x.first.second + 1] = true;

                    bfs.push(make_pair(make_pair(x.first.first, x.first.second + 1), x.second + 1));
                }
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    vector<vector<lol>> tm;
    vector<vector<lol>> ta;
    cin >> n >> m;
    vector<vector<bool>> visited;
    pair<lol, lol> src;
    vector<vector<pair<lol, lol>>> parent;
    vector<pair<lol, lol>> mo;
    for (lol i = 0; i < n; i++)
    {
        vector<bool> y;
        vector<lol> x;
        vector<pair<lol, lol>> x1;
        for (lol j = 0; j < m; j++)
        {
            x.push_back(LONG_LONG_MAX);
            x1.push_back(make_pair(-1, -1));
            char c;
            cin >> c;
            if (c == '.')
                y.push_back(false);
            else if (c == 'M')
            {
                y.push_back(false);
                mo.push_back(make_pair(i, j));
            }
            else if (c == 'A')
            {
                y.push_back(false);
                src = make_pair(i, j);
            }
            else
                y.push_back(true);
        }
        visited.push_back(y);
        parent.push_back(x1);
        ta.push_back(x);
        tm.push_back(x);
    }

    call(src, visited, parent, 1, tm, ta, mo);

    call(src, visited, parent, 0, tm, ta, mo);

    for (lol i = 0; i < m; i++)
    {
        if (ta[0][i] < tm[0][i])
        {
            cout << "YES"
                 << "\n";
            string ans = "";
            pair<lol, lol> cur = make_pair(0, i);
            while (cur != src)
            {
                pair<lol, lol> sec = parent[cur.first][cur.second];
                if (sec.first > cur.first)
                    ans.push_back('U');
                else if (sec.first < cur.first)
                    ans.push_back('D');
                else if (sec.second > cur.second)
                    ans.push_back('L');
                else
                    ans.push_back('R');
                cur = sec;
            }
            reverse(ans.begin(), ans.end());
            cout << ans.size() << '\n';
            cout << ans;

            return 0;
        }
        if (ta[n - 1][i] < tm[n - 1][i])
        {
            cout << "YES"
                 << "\n";
            string ans = "";
            pair<lol, lol> cur = make_pair(n - 1, i);
            while (cur != src)
            {
                pair<lol, lol> sec = parent[cur.first][cur.second];
                if (sec.first > cur.first)
                    ans.push_back('U');
                else if (sec.first < cur.first)
                    ans.push_back('D');
                else if (sec.second > cur.second)
                    ans.push_back('L');
                else
                    ans.push_back('R');
                cur = sec;
            }
            reverse(ans.begin(), ans.end());
            cout << ans.size() << '\n';
            cout << ans;

            return 0;
        }
    }
    for (lol i = 0; i < n; i++)
    {
        if (ta[i][0] < tm[i][0])
        {
            cout << "YES"
                 << "\n";
            string ans = "";
            pair<lol, lol> cur = make_pair(i, 0);
            while (cur != src)
            {
                pair<lol, lol> sec = parent[cur.first][cur.second];
                if (sec.first > cur.first)
                    ans.push_back('U');
                else if (sec.first < cur.first)
                    ans.push_back('D');
                else if (sec.second > cur.second)
                    ans.push_back('L');
                else
                    ans.push_back('R');
                cur = sec;
            }
            reverse(ans.begin(), ans.end());
            cout << ans.size() << '\n';
            cout << ans;

            return 0;
        }
        if (ta[i][m - 1] < tm[i][m - 1])
        {
            cout << "YES"
                 << "\n";
            string ans = "";
            pair<lol, lol> cur = make_pair(i, m - 1);
            while (cur != src)
            {
                pair<lol, lol> sec = parent[cur.first][cur.second];
                if (sec.first > cur.first)
                    ans.push_back('U');
                else if (sec.first < cur.first)
                    ans.push_back('D');
                else if (sec.second > cur.second)
                    ans.push_back('L');
                else
                    ans.push_back('R');
                cur = sec;
            }
            reverse(ans.begin(), ans.end());
            cout << ans.size() << '\n';
            cout << ans;

            return 0;
        }
    }
    cout << "NO";

    return 0;
}