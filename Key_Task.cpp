#include <bits/stdc++.h>
#define lol long long 
using namespace std;
lol n, m;
bool check(lol x, lol y)
{
    return (x >= 0 && x < n && y >= 0 && y < m);
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    while (1)
    {
        cin >> n >> m;
        if (n == 0 && m == 0)
            break;
        string a[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        queue<pair<pair<lol, lol>, pair<lol, lol>>> q;
        lol d[n][m][16];
        for (lol i = 0; i < n; i++)
        {
            for (lol j = 0; j < m; j++)
            {
                for (lol k = 0; k < 16; k++)
                {
                    d[i][j][k] = LONG_LONG_MAX;
                }
                if (a[i][j] == '*')
                {
                    q.push({{i, j}, {0, 0}});
                }
            }
        }
        lol dx[4] = {-1, 0, 0, 1};
        lol dy[4] = {0, 1, -1, 0};
        while (!q.empty())
        {
            pair<pair<lol, lol>, pair<lol, lol>> x = q.front();
            q.pop();

            lol i = x.first.first;
            lol j = x.first.second;
            lol dis = x.second.first;
            lol key = x.second.second;

            if (d[i][j][key]!=LONG_LONG_MAX)
                continue;
            d[i][j][key] = dis;
            if (a[i][j] == 'X')
                continue;
            if (a[i][j] == 'b')
                key |= 1;
            if (a[i][j] == 'y')
                key |= (1 << 1);
            if (a[i][j] == 'r')
                key |= (1 << 2);
            if (a[i][j] == 'g')
                key |= (1 << 3);

            for (lol k = 0; k < 4; k++)
            {
                if (check(i + dx[k], j + dy[k]))
                {
                    lol ni = i + dx[k];
                    lol nj = j + dy[k];
                    if (a[ni][nj] == '#')
                        continue;
                    else if (a[ni][nj] == '.' || a[ni][nj] == 'X')
                    {
                        if (d[ni][nj][key] > dis + 1)
                        {
                            q.push({{ni, nj}, {dis + 1, key}});
                        }
                    }
                    else if (a[ni][nj] == 'G')
                    {
                        if (key & (1 << 3))
                        {
                            if (d[ni][nj][key] > dis + 1)
                            {
                                q.push({{ni, nj}, {dis + 1, key}});
                            }
                        }
                        else
                            continue;
                    }
                    else if (a[ni][nj] == 'R')
                    {
                        if (key & (1 << 2))
                        {
                            if (d[ni][nj][key] > dis + 1)
                            {
                                q.push({{ni, nj}, {dis + 1, key}});
                            }
                        }
                        else
                            continue;
                    }
                    else if (a[ni][nj] == 'Y')
                    {
                        if (key & (1 << 1))
                        {
                            if (d[ni][nj][key] > dis + 1)
                            {
                                q.push({{ni, nj}, {dis + 1, key}});
                            }
                        }
                        else
                            continue;
                    }
                    else if (a[ni][nj] == 'B')
                    {
                        if (key & (1 << 0))
                        {
                            if (d[ni][nj][key] > dis + 1)
                            {
                                q.push({{ni, nj}, {dis + 1, key}});
                            }
                        }
                        else
                            continue;
                    }
                    else
                    {
                        if (d[ni][nj][key] > dis + 1)
                        {
                            q.push({{ni, nj}, {dis + 1, key}});
                        }
                    }
                }
            }
        }
        lol ans = LONG_LONG_MAX;
        for (lol i = 0; i < n; i++)
        {
            for (lol j = 0; j < m; j++)
            {
                for (lol k = 0; k < 16; k++)
                {
                    if (a[i][j] == 'X')
                        ans = min(ans, d[i][j][k]);
                }
            }
        }
        if (ans == LONG_LONG_MAX)
        {
            cout << "The poor student is trapped!" << endl;
        }
        else
            cout << "Escape possible in " << ans << " steps." << endl;

        cin.ignore();
    }

    return 0;
}