#include <bits/stdc++.h>
#define lol long long
using namespace std;
lol lcs(string s1)
{
    lol ns1 = s1.size(); string s2=s1;
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
            if (s1[i - 1] == s2[j - 1]&&i!=j)
                dp[i][j] = dp[i - 1][j - 1] +1;
            else
            {
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
    } 
    return dp[ns1][ns2];
}
int main()
{
    string a;
    cin >> a ;
       cout<<lcs(a);
    return 0;
}