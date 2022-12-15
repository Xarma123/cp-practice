#include <bits/stdc++.h>
#define lol long long
using namespace std;
lol m;
bool check(lol i, lol j)
{
    return ((i >= 0 && i < 2) && (j >= 0 && j < m));
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

        cin >> m;
        string a[2];
        cin >> a[0] >> a[1];
        bool dp[2][m];
        for (lol i = 0; i < m; i++)
        {
            if (i == 0)
            {
                if (a[0][i] == 'B')
                {
                    dp[0][i] = true;
                }
                else
                    dp[0][i] = false;
                if (a[1][i] == 'B')
                {
                    dp[1][i] = true;
                }
                else
                    dp[1][i] = false;
            }
            else
            {
                // 0
                if (a[0][i] == 'B')
                {
                    if (a[1][i] == 'B')
                    {
                        if (dp[1][i - 1])
                            dp[0][i] = true;
                        else
                            dp[0][i] = false;
                    }
                    else
                    {

                        dp[0][i] = dp[0][i - 1];
                    }
                }
                else
                    dp[0][i] = false;

                // 1
                if (a[1][i] == 'B')
                {
                    if (a[0][i] == 'B')
                    {
                        if (dp[0][i - 1])
                            dp[1][i] = true;
                        else
                            dp[1][i] = false;
                    }
                    else
                    {

                        dp[1][i] = dp[1][i - 1];
                    }
                }
                else
                    dp[1][i] = false;
            }
        }
        if (dp[0][m - 1] || dp[1][m - 1])
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}