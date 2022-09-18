#include <bits/stdc++.h>
#define lol long long
using namespace std;
lol min(string s1, string s2)
{
    lol ns1 = s1.size();
    lol ns2 = s2.size();
    lol dp[ns1 + 1][ns2 + 1];
    for (lol i = 0; i <= ns1; i++)
    {
        dp[i][0] = 0;
    }
    for (lol i = 0; i <= ns2; i++)
    {
        dp[0][i] = 0;
    }
    for (lol i = 1; i <= ns1; i++)
    {
        for (lol j = 1; j <= ns2; j++)
        {
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
            {
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
    }
    lol ans = 0,ans2=0;
    if (ns1 > dp[ns1][ns2])
    {
        ans += ns1 - dp[ns1][ns2];
    }
    if (ns2 > dp[ns1][ns2])
    {
        ans2 += ns2 - dp[ns1][ns2];
    }
    return max(ans,ans2);
}
int main()
{
    string a, b;
    cin >> a >> b;

    cout << min(a, b);

    return 0;
}