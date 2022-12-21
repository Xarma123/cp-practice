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
        lol w, h;
        cin >> w >> h;
        if (w == 0 && h == 0)
            break;
        string a[h];
        for (lol i = 0; i < h; i++)
        {
            cin >> a[i];
        }
        lol c = 0;
        for (lol i = 0; i < h; i++)
        {
            for (lol j = 0; j < w; j++)
            {
                if (a[i][j] == '*')
                {
                    a[i][j] = char('0' + c);
                    c++;
                }
            }
        }
   

        queue<vector<lol>> q;
        lol d[h][w][(1 << c)];
        for (lol i = 0; i < h; i++)
        {
            for (lol j = 0; j < w; j++)
            {
                for (lol k = 0; k < (1 << c); k++)
                {
                    d[i][j][k] = LONG_LONG_MAX;
                }
                if (a[i][j] == 'o')
                {
                    q.push({0, i, j, 0});
                }
            }
        }

        lol dx[4] = {-1, 0, 0, 1};
        lol dy[4] = {0, -1, 1, 0};
        while (!q.empty())
        {
            vector<lol> x = q.front();
            q.pop();
            lol i = x[1];
            lol j = x[2];
            lol dis = x[0];
            lol fil = x[3];
            if (i < 0 || i >= h || j < 0 || j >= w)
                continue;
            if (a[i][j] >= '0' && a[i][j] <= '9')
            {
                lol v = a[i][j] - '0';
                fil |= (1ll << v);
            }
            if (d[i][j][fil] != LONG_LONG_MAX)
                continue;
            if (a[i][j] == 'x')
                continue;
            d[i][j][fil] = dis;

            for (lol k = 0; k < 4; k++)
            {
                q.push({dis + 1, i + dx[k], j + dy[k], fil});
            }
        }
        lol ans = LONG_LONG_MAX;
        for (lol i = 0; i < h; i++)
        {
            for (lol j = 0; j < w; j++)
            {
                ans = min(ans, d[i][j][(1 << c) - 1]);
            }
        }
        if (ans == LONG_LONG_MAX)
            ans = -1;
        cout << ans << endl;
    }

    return 0;
}