#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n = 5;
    lol dp[2 * n + 1][2 * n + 1];
    for (lol i = 0; i <= 2 * n ; i++)
    {
        dp[i][0] = 1;
    }
    for (lol i = 1; i <= 2 * n ; i++)
    {
        for (lol j = 1; j <= 2 * n  && j <= i; j++)
        {
            if (i != j)
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
            else
                dp[i][j] = 1; 
           
          
        }
       
    }
    return 0;
}