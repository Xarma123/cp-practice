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
        string a[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        queue<pair<lol, lol>> q;
        lol d[n][m];
        memset(d, -1, sizeof(d));
        for (lol i = 0; i < n; i++)
        {
            for (lol j = 0; j < m; j++)
            {
                if (a[i][j] == '1')
                {
                    q.push({i, j});
                    d[i][j] = 0;
                }
            }
        }
        while (!q.empty())
        {
            pair<lol, lol> t = q.front();
            q.pop();
            lol dx[4] = {-1, 0, 0, 1};
            lol dy[4] = {0, -1, 1, 0};
            for (lol i = 0; i < 4; i++)
            {
                lol x = t.first + dx[i];
                lol y = t.second + dy[i];
                if (x < 0 || x >= n || y < 0 || y >= m)
                    continue;
                if (d[x][y] == -1)
                {
                    d[x][y] = 1 + d[t.first][t.second];
                    q.push({x, y});
                }
            }
        }
        for (lol i = 0; i < n; i++)
        {
            for (lol j = 0; j < m; j++)
            {
                cout << d[i][j] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}