#include <bits/stdc++.h>
using namespace std;
#define lol long long
lol n, m, k;
string a[1005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m >> k;
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    if (k % 2 != 0)
    {
        cout << "IMPOSSIBLE";
        return 0;
    }
    lol si, sj;
    lol d[n][m];
    for (lol i = 0; i < n; i++)
    {
        for (lol j = 0; j < m; j++)
        {
            if (a[i][j] == 'X')
            {
                si = i;
                sj = j;
            }
            d[i][j] = LONG_LONG_MAX;
        }
    }

    queue<pair<lol, lol>> q;
    q.push({si, sj});
    d[si][sj] = 0;
    while (!q.empty())
    {
        pair<lol, lol> b = q.front();
        q.pop();
        lol dx[4] = {-1, 0, 0, 1};
        lol dy[4] = {0, -1, 1, 0};
        for (lol i = 0; i < 4ll; i++)
        {
            lol x = dx[i] + b.first;
            lol y = dy[i] + b.second;
            if (x >= 0 && x < n && y >= 0 && y < m && a[x][y] != '*' && d[b.first][b.second] + 1 < d[x][y])
            {
                d[x][y] = d[b.first][b.second] + 1;
                q.push({x, y});
            }
        }
    }
    string ans = "";
    while (k--)
    {
        if (si + 1 < n && a[si + 1][sj] != '*' && d[si + 1][sj] <= k)
        {
            ans += 'D';
            si++;
            continue;
        }
        if (sj - 1 >= 0 && a[si][sj - 1] != '*' && d[si][sj - 1] <= k)
        {
            ans += 'L';
            sj--;
            continue;
        }
        if (sj + 1 < m && a[si][sj + 1] != '*' && d[si][sj + 1] <= k)
        {
            ans += 'R';
            sj++;
            continue;
        }
        if (si - 1 >= 0 && a[si - 1][sj] != '*' && d[si - 1][sj] <= k)
        {
            ans += 'U';
            si--;
            continue;
        }
        ans = "IMPOSSIBLE";
        break;
    }
    cout << ans;

    return 0;
}
