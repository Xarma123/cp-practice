#include <bits/stdc++.h>
#define lol long long
using namespace std;
string a[8];
lol dp[8][8];
set<vector<lol>> q;
void dfs(lol x, lol y, lol l)
{

    if (q.count({x, y, l}))
        return;
    if (l > 16)
        return;
    if (x - l >= 0 && a[x - l][y] == 'S')
        return;
    lol dy[9] = {0, -1, -1, -1, 0, 0, 1, 1, 1};
    lol dx[9] = {0, 0, 1, -1, 1, -1, 0, -1, 1};
    for (lol i = 0; i < 9; i++)
    {
        lol xx = x + dx[i];
        lol yy = y + dy[i];
        if (xx >= 0 && xx < 8 && yy >= 0 && yy < 8)
        {
            bool go = true;
            if (xx - l >= 0 && a[xx - l][yy] == 'S')
                go = false;
            if (go)
            {
                dp[xx][yy] = dp[x][y] + 1;
                dfs(xx, yy, l + 1);
            }
        }
    }
    q.insert({x, y, l});
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    for (lol i = 0; i < 8; i++)
    {
        cin >> a[i];
    }
    lol x, y;
    for (lol i = 0; i < 8; i++)
    {
        for (lol j = 0; j < 8; j++)
        {
            dp[i][j] = LONG_LONG_MAX;
            if (a[i][j] == 'M')
            {
                x = i;
                y = j;
                dp[i][j] = 0;
                break;
            }
        }
    }
    dfs(x, y, 0);
    if (dp[0][7] == LONG_LONG_MAX)
        cout << "LOSE" << endl;
    else
        cout << "WIN" << endl;

    return 0;
}