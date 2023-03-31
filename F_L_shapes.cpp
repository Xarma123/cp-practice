#include <bits/stdc++.h>
#define lol long long
using namespace std;
lol n, m;
bool vis[101][101];
bool check(lol i, lol j)
{
    if (vis[i][j])
        return false;
    lol dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
    lol dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
    for (lol k = 0; k < 8; k++)
    {
        if (i + dx[k] >= 0 && i + dx[k] < n && j + dy[k] >= 0 && j + dy[k] < m)
        {

            if (vis[i + dx[k]][j + dy[k]])
                return false;
        }
    }
    return true;
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol t;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        string a[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        bool ans = true;
        memset(vis, false, sizeof(vis));
        // l1
        for (lol i = 0; i < n - 1; i++)
        {
            for (lol j = 0; j < m - 1; j++)
            {
                if (a[i][j] == '*' && a[i + 1][j] == '*' && a[i + 1][j + 1] == '*')
                {
                    ans &= check(i, j);
                    ans &= check(i + 1, j);
                    ans &= check(i + 1, j + 1);
                    vis[i][j] = true;
                    vis[i + 1][j] = true;
                    vis[i + 1][j + 1] = true;
                }
            }
        }
        // l2
        for (lol i = 0; i < n - 1; i++)
        {
            for (lol j = 1; j < m; j++)
            {
                if (a[i][j] == '*' && a[i + 1][j] == '*' && a[i + 1][j - 1] == '*')
                {
                    ans &= check(i, j);
                    ans &= check(i + 1, j);
                    ans &= check(i + 1, j - 1);
                    vis[i][j] = true;
                    vis[i + 1][j] = true;
                    vis[i + 1][j - 1] = true;
                }
            }
        }
        for (lol i = 1; i < n; i++)
        {
            for (lol j = 1; j < m; j++)
            {
                if (a[i][j] == '*' && a[i - 1][j] == '*' && a[i - 1][j - 1] == '*')
                {
                    ans &= check(i, j);
                    ans &= check(i - 1, j);
                    ans &= check(i - 1, j - 1);
                    vis[i][j] = true;
                    vis[i - 1][j] = true;
                    vis[i - 1][j - 1] = true;
                }
            }
        }
        for (lol i = 1; i < n; i++)
        {
            for (lol j = 0; j < m - 1; j++)
            {
                if (a[i][j] == '*' && a[i - 1][j] == '*' && a[i - 1][j + 1] == '*')
                {
                    ans &= check(i, j);
                    ans &= check(i - 1, j);
                    ans &= check(i - 1, j + 1);
                    vis[i][j] = true;
                    vis[i - 1][j] = true;
                    vis[i - 1][j + 1] = true;
                }
            }
        }
        for (lol i = 0; i < n; i++)
        {
            for (lol j = 0; j < m; j++)
            {
                if (a[i][j] == '*' && vis[i][j] == false)
                    ans = false;
            }
        }

        if (ans)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}