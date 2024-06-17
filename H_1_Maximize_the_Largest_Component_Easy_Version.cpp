#include <bits/stdc++.h>
using namespace std;
#define lol int
int main()
{
    ios_base::sync_with_stdio(false);
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
        lol c = 0;
        map<lol, lol> sz, lf, rt, tp, btm;

        for (lol i = 0; i < n; i++)
        {
            for (lol j = 0; j < m; j++)
            {
                if (a[i][j] == '#')
                {
                    a[i][j] = 'a';
                    q.push({i, j});
                    lf[c] = j;
                    rt[c] = j;
                    tp[c] = i;
                    btm[c] = i;
                    while (!q.empty())
                    {

                        sz[c]++;
                        pair<lol, lol> top = q.front();
                        lol x = top.first;
                        lol y = top.second;

                        lf[c] = min(lf[c], y);
                        rt[c] = max(rt[c], y);
                        tp[c] = min(tp[c], x);
                        btm[c] = max(btm[c], x);
                        q.pop();
                        lol dx[4] = {-1, 0, 0, 1};
                        lol dy[4] = {0, -1, 1, 0};
                        for (lol k = 0; k < 4; k++)
                        {
                            lol nx = x + dx[k];
                            lol ny = y + dy[k];
                            if (nx >= 0 && nx < n && ny >= 0 && ny < m)
                            {
                                if (a[nx][ny] == '#')
                                {
                                    a[nx][ny] = 'a';
                                    q.push({nx, ny});
                                }
                            }
                        }
                    }
                    c++;
                }
            }
        }
        lol h[n];
        lol v[m];

        memset(h, 0, sizeof(h));
        memset(v, 0, sizeof(v));

        for (lol i = 0; i < c; i++)
        {
            v[max(lf[i] - 1, 0)] += sz[i];
            if (rt[i] + 2 < m)
                v[rt[i] + 2] -= sz[i];
            h[max(tp[i] - 1, 0)] += sz[i];
            if (btm[i] + 2 < n)
                h[btm[i] + 2] -= sz[i];
        }
        for (lol i = 1; i < n; i++)
        {
            h[i] += h[i - 1];
        }
        for (lol i = 1; i < m; i++)
        {
            v[i] += v[i - 1];
        }
        lol rw[n], col[m];
        for (lol i = 0; i < n; i++)
        {
            lol x = 0;
            for (lol j = 0; j < m; j++)
            {
                if (a[i][j] == '.')
                    x++;
            }
            rw[i] = x;
        }
        for (lol j = 0; j < m; j++)
        {
            lol x = 0;
            for (lol i = 0; i < n; i++)
            {
                if (a[i][j] == '.')
                    x++;
            }
            col[j] = x;
        }

        lol ans = 0;
        for (lol i = 0; i < n; i++)
        {
            ans = max(ans, rw[i] + h[i]);
        }
        for (lol i = 0; i < m; i++)
        {
            ans = max(ans, col[i] + v[i]);
        }

        cout << ans << '\n';
    }

    return 0;
}