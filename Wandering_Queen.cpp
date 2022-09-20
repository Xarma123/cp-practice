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
        lol si = -1, sj;
        vector<vector<lol>> d(n, vector<lol>(m, LONG_LONG_MAX));
        vector<vector<lol>> dir(n, vector<lol>(m, 0));
        for (lol i = 0; i < n; i++)
        {
            for (lol j = 0; j < m; j++)
            {
                if (a[i][j] == 'S')
                {
                    d[i][j] = 0;
                    si = i;
                    sj = j;
                    break;
                }
            }
            if (si != -1)
                break;
        }

        queue<vector<lol>> q;
        q.push({si, sj, 0});
        while (!q.empty())
        {
            lol x = q.front()[0];
            lol y = q.front()[1];
            lol dis = q.front()[2];
            if (a[x][y] == 'F')
            {
                cout << dis << '\n';
                break;
            }
            q.pop();
            dir[x][y] = (1 << 8) - 1;

            for (lol i = y - 1; i >= 0 && !(dir[x][i] & (1 << 0)) && a[x][i] != 'X'; i--)
            {
                if (d[x][i] > dis + 1)
                {

                    d[x][i] = dis + 1;
                    q.push({x, i, d[x][i]});
                }
                dir[x][i] |= (1 << 0);
            }
            for (lol i = y + 1; i < m && !(dir[x][i] & (1 << 1)) && a[x][i] != 'X'; i++)
            {
                if (d[x][i] > dis + 1)
                {

                    d[x][i] = dis + 1;
                    q.push({x, i, d[x][i]});
                }
                dir[x][i] |= (1 << 1);
            }
            for (lol i = x - 1; i >= 0 && !(dir[i][y] & (1 << 2)) && a[i][y] != 'X'; i--)
            {
                if (d[i][y] > dis + 1)
                {

                    d[i][y] = dis + 1;
                    q.push({i, y, d[i][y]});
                }
                dir[i][y] |= (1 << 2);
            }
            for (lol i = x + 1; i < n && !(dir[i][y] & (1 << 3)) && a[i][y] != 'X'; i++)
            {
                if (d[i][y] > dis + 1)
                {

                    d[i][y] = dis + 1;
                    q.push({i, y, d[i][y]});
                }
                dir[i][y] |= (1 << 3);
            }

            for (lol i = x - 1, j = y - 1; i >= 0 && j >= 0 && !(dir[i][j] & (1 << 4)) && a[i][j] != 'X'; i--, j--)
            {
                if (d[i][j] > dis + 1)
                {

                    d[i][j] = dis + 1;
                    q.push({i, j, d[i][j]});
                }
                dir[i][j] |= (1 << 4);
            }
            for (lol i = x + 1, j = y - 1; i < n && j >= 0 && !(dir[i][j] & (1 << 5)) && a[i][j] != 'X'; i++, j--)
            {
                if (d[i][j] > dis + 1)
                {

                    d[i][j] = dis + 1;
                    q.push({i, j, d[i][j]});
                }
                dir[i][j] |= (1 << 5);
            }
            for (lol i = x + 1, j = y + 1; i < n && j < m && !(dir[i][j] & (1 << 6)) && a[i][j] != 'X'; i++, j++)
            {
                if (d[i][j] > dis + 1)
                {

                    d[i][j] = dis + 1;
                    q.push({i, j, d[i][j]});
                }
                dir[i][j] |= (1 << 6);
            }
            for (lol i = x - 1, j = y + 1; i >= 0 && j < m && !(dir[i][j] & (1 << 7)) && a[i][j] != 'X'; i--, j++)
            {
                if (d[i][j] > dis + 1)
                {

                    d[i][j] = dis + 1;
                    q.push({i, j, d[i][j]});
                }
                dir[i][j] |= (1 << 7);
            }
        }
        si = -1;
        if (q.empty())
            cout << -1 << '\n';
    }

    return 0;
}