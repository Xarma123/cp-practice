#include <bits/stdc++.h>
#define lol long long
using namespace std;
string a[505];
lol lev[505][505];
lol n, m, k;
void dfs(lol i, lol j, lol l)
{
    if (i >= 0 && i < n && j >= 0 && j < m && a[i][j] == '.')
    {
        lev[i][j] = l;
        lol dx[4] = {-1, 1, 0, 0};
        lol dy[4] = {0, 0, -1, 1};
        a[i][j] = 'A';
        for (lol q = 0; q < 4; q++)
        {
            dfs(dx[q] + i, dy[q] + j, l + 1);
        }
    }
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> k;

    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (lol i = 0; i < n; i++)
    {
        lol j;
        for (j = 0; j < m; j++)
        {
            if (a[i][j] == '.')
            {
                dfs(i, j, 0);
                break;
            }
        }
        if (j < m)
            break;
    }
    set<pair<lol, pair<lol, lol>>> x;
    for (lol i = 0; i < n; i++)
    {
        for (lol j = 0; j < m; j++)
        {
            if (a[i][j] == 'A')
                x.insert({-lev[i][j], {i, j}}), a[i][j] = '.';
        }
    }
    while (k--)
    {
        a[(*x.begin()).second.first][(*x.begin()).second.second] = 'X';
        x.erase(x.begin());
    }

    for (lol i = 0; i < n; i++)
    {
        cout << a[i] << endl;
    }

    return 0;
}