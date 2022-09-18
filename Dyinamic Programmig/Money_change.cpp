#include <bits/stdc++.h>
#define lol long long
using namespace std;
lol a[3] = {1, 3, 4};
lol solve(lol m, lol n,lol dp[][4])
{

    if (m == 0)
    {
        return 0;
    }
    if (n == 0)
    {
        return LONG_LONG_MAX;   // long_max for min no of coins
    }
    if (a[n - 1] <= m)  
    {
        if(dp[m-a[n-1]][n]==-1)
        {
            dp[m-a[n-1]][n] = solve(m - a[n - 1], n,dp);
        }
        if(dp[m][n-1]==-1)
        {
            dp[m][n-1] = solve(m , n-1,dp);
        }

  return min(dp[m-a[n-1]][n]+1,dp[m][n-1]); // min() for min no of coins
    }
       if(dp[m][n-1]==-1)
        {
            dp[m][n-1] = solve(m , n-1,dp);
        }

    return  dp[m][n-1];
}

int main()
{
    lol m;
    cin >> m; 
     cin>>a[0]>>a[1]>>a[2];
    lol dp[m + 1][4]; memset(dp,-1,sizeof(dp));
    cout << solve(m, 3, dp); 
    return 0;
}