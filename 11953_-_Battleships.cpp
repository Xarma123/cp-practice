#include <bits/stdc++.h>
#define lol long long
using namespace std;
bool dfs(lol x, lol y, lol &n, string a[])
{
    if (x < 0 || x >= n || y < 0 || y >= n)
        return false;
    bool f = false;
    if (a[x][y] == 'x' || a[x][y] == '@')
    {
        if (a[x][y] == 'x')
            f = true;
        a[x][y] = '.';
        lol dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
        lol dy[8] = {-1, 0, 1, -1, 1, 1, 0, -1};
        for (lol i = 0; i < 8; i++)
        {
            f |= dfs(x + dx[i], y + dy[i], n, a);
        }
        return f;
    }
    else
        return f;
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol t;
    cin >> t;
    lol c = 1;
    while (t--)
    {
        lol n;
        cin >> n;
        string a[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        lol ans = 0;
        for (lol i = 0; i < n; i++)
        {
            for (lol j = 0; j < n; j++)
            {
                if (a[i][j] == 'x' || a[i][j] == '@')
                {
                    if (dfs(i, j, n, a))
                        ans++;
                }
            }
        }
        cout << "Case " << c << ": " << ans << endl;
        c++;
    }

    return 0;
}