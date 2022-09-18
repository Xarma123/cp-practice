#include <bits/stdc++.h>
#define lol long long
using namespace std;
lol lcs(string s1, string s2)
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
    if(dp[x][ns2]==ns2)
    return 0;
    else
    { 
        


    } 
     

    




}
int main()
{ 
    lol n ; cin>>n;
    char a[n+1];
    for (lol i = 0; i < n; i++)
    {
        cin>>a[i];
    }
      a[n]='\0';
    lol m; cin>>m;
    char b[n+1];
    for (lol i = 0; i < n; i++)
    {
        cin>>b[i];
    }
      b[n]='\0';
    
        
    cout<<lcs(a,b);
    return 0;
}