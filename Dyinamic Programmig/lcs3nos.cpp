#include <bits/stdc++.h>
#define lol long long
using namespace std;
lol lcs(lol s1[], lol s2[], lol s3[], lol n, lol m, lol l)
{
    lol ns1 = n;
    lol ns2 = m;
    lol ns3 = l;
    lol dp[ns1 + 1][ns2 + 1][ns3 + 1];
    for (lol i = 0; i <= ns1; i++)
    {
        for (lol j = 0; j <= ns3; j++)
        {
            dp[i][0][j] = 0;
        }
    }
    for (lol i = 0; i <= ns2; i++)
    {
        for (lol j = 0; j <= ns3; j++)
        {
            dp[0][i][j] = 0;
        }
    }
    for (lol i = 0; i <= ns1; i++)
    {
        for (lol j = 0; j <= ns2; j++)
        {
            dp[i][j][0] = 0;
        }
    }

    for (lol i = 1; i <= ns1; i++)
    {

        for (lol j = 1; j <= ns2; j++)
        {
            for (lol k = 1; k <= ns3; k++)
            {

                if (s1[i - 1] == s2[j - 1]&& s2[j-1]== s3[k - 1])
                    dp[i][j][k] = dp[i - 1][j - 1][k - 1] + 1;
                  
                else
                {
                    dp[i][j][k] = max(dp[i - 1][j][k], max(dp[i][j - 1][k], dp[i][j][k - 1]));
                   
                }
            }
        }
    }
    return dp[ns1][ns2][ns3];
}
int main()
{
    lol n;
    cin >> n;
    lol a[n];
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    lol m;
    cin >> m;
    lol b[m];
    for (lol i = 0; i < m; i++)
    {
        cin >> b[i];
    }
    lol l;
    cin >> l;
    lol c[l];
    for (lol i = 0; i < l; i++)
    {
        cin >> c[i];
    }

    cout << lcs(a, b, c, n, m, l);
    return 0;
}