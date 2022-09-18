#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    lol n, m;
    cin >> n >> m;
    bool visited[n][m];
    pair<lol, lol> parent[n][m];
    pair<lol, lol> source;
    pair<lol, lol> dest;
    for (lol i = 0; i < n; i++)
    {
        for (lol j = 0; j < m; j++)
        {
            char c;
            cin >> c;
            if (c == '.')
                visited[i][j] = false;
            else if (c == 'A')
            {
                source = make_pair(i, j);
                visited[i][j] = false;
            }
            else if (c == 'B')
            {
                dest = make_pair(i, j);
                visited[i][j] = false;
            }
            else
                visited[i][j] = true;
        }
    }
    queue<pair<lol, lol>> bfs;
    bfs.push(source);
    bool ans = false;
    while (!bfs.empty())
    {

        pair<lol, lol> cur = bfs.front();
        visited[cur.first][cur.second] = true;

        if (cur == dest)
        {
            ans = true;
        }
        bfs.pop();
        if (cur.first + 1 < n)
        {
            if (!visited[cur.first + 1][cur.second])
            {
                pair<lol, lol> x = make_pair(cur.first + 1, cur.second);
                parent[cur.first + 1][cur.second] = cur;
                visited[cur.first + 1][cur.second] = true;
                bfs.push(x);
            }
        }
        if (cur.first - 1 >= 0)
        {
            if (!visited[cur.first - 1][cur.second])
            {
                pair<lol, lol> x = make_pair(cur.first - 1, cur.second);
                parent[cur.first - 1][cur.second] = cur;
                visited[cur.first - 1][cur.second] = true;
                bfs.push(x);
            }
        }
        if (cur.second - 1 >= 0)
        {
            if (!visited[cur.first][cur.second - 1])
            {
                pair<lol, lol> x = make_pair(cur.first, cur.second - 1);
                parent[cur.first][cur.second - 1] = cur;
                visited[cur.first][cur.second - 1] = true;
                bfs.push(x);
            }
        }
        if (cur.second + 1 < m)
        {
            if (!visited[cur.first][cur.second + 1])
            {
                pair<lol, lol> x = make_pair(cur.first, cur.second + 1);
                parent[cur.first][cur.second + 1] = cur;
                visited[cur.first][cur.second + 1] = true;
                bfs.push(x);
            }
        }
    }
    if (ans)
    {
        cout << "YES" << '\n';
        string an = "";
        pair<lol, lol> cur = dest;
        while (cur != source)
        {

            pair<lol, lol> sec = parent[cur.first][cur.second];

            if (sec.first != cur.first)
            {
                if (sec.first > cur.first)
                    an.push_back('U');
                else
                    an.push_back('D');
            }
            if (sec.second != cur.second)
            {
                if (sec.second > cur.second)
                    an.push_back('L');
                else
                    an.push_back('R');
            }
            cur = sec;
        }
        reverse(an.begin(), an.end());
        cout << an.size() << '\n';
        cout << an;
    }
    else
        cout << "NO";

    return 0;
}