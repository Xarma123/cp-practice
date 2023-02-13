#include <bits/stdc++.h>
#define lol long long
using namespace std;
lol n, m;
void dfs(string a[], lol x, lol y)
{
    if (a[x][y] == '#')
    {
        return;
    }
    if (a[x][y] == 'g' || a[x][y] == '/')
        return;
    if (a[x][y] == 'G')
        a[x][y] = 'g';
    else
        a[x][y] = '/';
    lol dx[4] = {-1, 0, 0, 1};
    lol dy[4] = {0, -1, 1, 0};
    for (lol i = 0; i < 4; i++)
    {
        if (x + dx[i] >= 0 && x + dx[i] < n && y + dy[i] >= 0 && y + dy[i] < m)
        {
            dfs(a, x + dx[i], y + dy[i]);
        }
    }
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
        for (lol i = 0; i < n; i++)
        {
            for (lol j = 0; j < m; j++)
            {
                if (a[i][j] == 'B')
                {
                    if (i - 1 >= 0)
                    {
                        if (a[i - 1][j] == 'G')
                            ans = false;
                        else if (a[i - 1][j] != 'B')
                            a[i - 1][j] = '#';
                    }
                    if (i + 1 < n)
                    {
                        if (a[i + 1][j] == 'G')
                            ans = false;
                        else if (a[i + 1][j] != 'B')
                            a[i + 1][j] = '#';
                    }
                    if (j - 1 >= 0)
                    {
                        if (a[i][j - 1] == 'G')
                            ans = false;
                        else if (a[i][j - 1] != 'B')
                            a[i][j - 1] = '#';
                    }
                    if (j + 1 < m)
                    {
                        if (a[i][j + 1] == 'G')
                            ans = false;
                        else if (a[i][j + 1] != 'B')
                            a[i][j + 1] = '#';
                    }
                }
            }
        }
        if (ans)
            dfs(a, n - 1, m - 1);
        for (lol i = 0; i < n; i++)
        {
            for (lol j = 0; j < m; j++)
            {
                if (a[i][j] == 'G')
                    ans = false;
            }
        }
        if (ans)
            cout << "Yes" << '\n';
        else
            cout << "No" << '\n';
    }

    return 0;
}