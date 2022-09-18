#include <bits/stdc++.h>
#define lol long long
using namespace std;
lol lcs(lol s1[], lol s2[],lol n , lol m )
{
    lol ns1 = n;
    lol ns2 = m;
    lol dp[ns1 + 1][ns2 + 1];
    for (lol i = 0; i <= ns1; i++)
    {
        dp[i][0] = 0;
    }
    for (lol i = 0; i <= ns2; i++)
    {
        dp[0][i] = 0;
    } 
    lol x = 0;
    for (lol i = 1; i <= ns1; i++)
    {  x  = 1-x;
        for (lol j = 1; j <= ns2; j++)
        {    if(x==1)
           { if (s1[i - 1] == s2[j - 1])
                dp[x][j] = dp[x - 1][j - 1] +1;
            else
            {
                dp[x][j] = max(dp[x][j - 1], dp[x - 1][j]);
            }  
           
           }
           else
           { 
             if (s1[i - 1] == s2[j - 1])
                dp[x][j] = dp[x + 1][j - 1] +1;
          else
            {
                dp[x][j] = max(dp[x][j - 1], dp[x + 1][j]);
            } 

           }
        }
    } 
    return dp[x][ns2]; 
    





}
int main()
{ 
    lol n ; cin>>n;
    lol a[n+1];
    for (lol i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    
    lol m; cin>>m;
    lol b[n+1];
    for (lol i = 0; i < n; i++)
    {
        cin>>b[i];
    }
    
    
        
    cout<<lcs(a,b,n,m);
    return 0;
}