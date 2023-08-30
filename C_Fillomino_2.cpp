#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    lol n;
    cin >> n;
    lol p[n];
    for (lol i = 0; i < n; i++)
    {
        cin >> p[i];
    }
    lol ans[n][n];
    memset(ans, -1, sizeof(ans));
    for (lol i = 0; i < n; i++)
    {
        lol c = p[i] - 1;
        lol x = i, y = i;
        ans[i][i] = p[i];
        while (c > 0)
        {
            if (y - 1 >= 0 && ans[x][y - 1] == -1)
            {
                y--;
            }
            else
            {
                x++;
            }
            ans[x][y] = p[i];
            c--;
        }
    }
    for (lol i = 0; i < n; i++)
    {
        for (lol j = 0; j <= i; j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << '\n';
    }
}