#include <bits/stdc++.h>
#define lol long long
using namespace std;
string a[200];
lol n;
void dfs(lol x, lol y)
{

    if (x >= n || x < 0)
        return;
    if (y >= a[x].size() || y < 0)
        return;
    if (a[x][y] == 'X' || a[x][y] == '#')
        return;

    a[x][y] = '#';

    dfs(x + 1, y);
    dfs(x - 1, y);
    dfs(x, y + 1);
    dfs(x, y - 1);
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
        n = 0;
        while (getline(cin, a[n]))
        {
            if (a[n][0] == '_')
                break;
            n++;
        }

        for (lol i = 0; i < n; i++)
        {

            for (lol j = 0; j < a[i].size(); j++)
            {

                if (a[i][j] == '*')
                    dfs(i, j);
            }
        }
        for (lol i = 0; i <= n; i++)
        {
            if (a[i] != "")
                cout << a[i] << endl;
        }
    }

    return 0;
}