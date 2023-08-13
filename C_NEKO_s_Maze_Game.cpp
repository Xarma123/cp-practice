#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, q;
    cin >> n >> q;
    lol c = 0;
    lol dp[2][n];
    for (lol i = 0; i < n; i++)
    {
        dp[0][i] = 0;
        dp[1][i] = 0;
    }
    bool lava[2][n];
    memset(lava, false, sizeof(lava));
    while (q--)
    {
        lol x, y;
        cin >> x >> y;
        x--;
        y--;
        if (!lava[x][y])
        {
            lava[x][y] = true;
            if (y - 1 >= 0 && lava[1 - x][y - 1])
            {
                dp[x][y]++;
                dp[1 - x][y - 1]++;
                if (dp[1 - x][y - 1] == 1)
                    c++;
            }
            if (lava[1 - x][y])
            {
                dp[x][y]++;
                dp[1 - x][y]++;
                if (dp[1 - x][y] == 1)
                    c++;
            }
            if (y + 1 < n && lava[1 - x][y + 1])
            {
                dp[x][y]++;
                dp[1 - x][y + 1]++;
                if (dp[1 - x][y + 1] == 1)
                    c++;
            }
            if (dp[x][y])
                c++;
        }
        else
        {

            if (dp[x][y])
                c--;
            dp[x][y] = 0;
            lava[x][y] = false;
            if (y - 1 >= 0 && lava[1 - x][y - 1])
            {

                dp[1 - x][y - 1]--;
                if (dp[1 - x][y - 1] == 0)
                    c--;
            }
            if (lava[1 - x][y])
            {

                dp[1 - x][y]--;
                if (dp[1 - x][y] == 0)
                    c--;
            }
            if (y + 1 < n && lava[1 - x][y + 1])
            {

                dp[1 - x][y + 1]--;
                if (dp[1 - x][y + 1] == 0)
                {
                    c--;
                }
            }
        }
        

        if (c == 0)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
}