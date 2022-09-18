#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, m;
    cin >> n >> m;
    lol mat[n][m];
    for (lol i = 0; i < n; i++)
    {
        for (lol j = 0; j < m; j++)
        {
            cin >> mat[i][j];
        }
    }

    lol dp1[n][m]; // 0,0 to x,y
    for (lol i = 0; i < n; i++)
    {
        for (lol j = 0; j < m; j++)
        {
            dp1[i][j] = mat[i][j];
            lol v = 0;
            if (i - 1 >= 0)
                v = max(v, dp1[i - 1][j]);
            if (j - 1 >= 0)
                v = max(v, dp1[i][j - 1]);
            dp1[i][j] += v;
        }
    }

    lol dp3[n][m]; // x,y to n,m
    for (lol i = n - 1; i >= 0; i--)
    {
        for (lol j = m - 1; j >= 0; j--)
        {
            dp3[i][j] = mat[i][j];
            lol v = 0;
            if (i + 1 < n)
                v = max(v, dp3[i + 1][j]);
            if (j + 1 < m)
                v = max(v, dp3[i][j + 1]);
            dp3[i][j] += v;
        }
    }
    lol dp2[n][m]; // n,0 to x,y
    for (lol i = n - 1; i >= 0; i--)
    {
        for (lol j = 0; j < m; j++)
        {
            dp2[i][j] = mat[i][j];
            lol v = 0;
            if (i + 1 < n)
                v = max(v, dp2[i + 1][j]);
            if (j - 1 >= 0)
                v = max(v, dp2[i][j - 1]);
            dp2[i][j] += v;
        }
    }

    lol dp4[n][m]; // x,t to 0,m
    for (lol j = m - 1; j >= 0; j--)
    {
        for (lol i = 0; i < n; i++)
        {

            dp4[i][j] = mat[i][j];
            lol v = 0;
            if (i - 1 >= 0)
                v = max(v, dp4[i - 1][j]);
            if (j + 1 < m)
                v = max(v, dp4[i][j + 1]);
            dp4[i][j] += v;
        }
    }
    lol ans = LONG_LONG_MIN;
    for (int i = 1; i < n - 1; i++)
        for (int j = 1; j < m - 1; j++)
        {
            lol case1 = dp1[i - 1][j] + dp3[i + 1][j] + dp2[i][j - 1] + dp4[i][j + 1];
            lol case2 = dp1[i][j - 1] + dp3[i][j + 1] + dp2[i + 1][j] + dp4[i - 1][j];
            ans = max(ans, max(case1, case2));
        }
    cout << ans;

    return 0;
}