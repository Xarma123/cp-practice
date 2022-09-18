#include<bits/stdc++.h>
#define lol long long
using namespace std; 
lol knap(lol W , lol w[],lol v[],lol n)
{ lol dp[W+1][n+1];
  for (lol i = 0; i <=W; i++)
  {
      dp[i][0]=0;
  }
  for (lol i = 0; i <=n; i++)
  {
      dp[0][i]=0;
  } 
  for (lol i = 1; i <= W; i++)
  {
     for (lol j = 1; j <=n; j++)
     {
        if(w[j-1]>i)
        {
            dp[i][j]=dp[i][j-1];
        } 
        else
        {
            dp[i][j]= max(dp[i][j-1],dp[i-w[j-1]][j-1]+v[j-1]);
        }
     }
     
  } 
  return dp[W][n];
  
   

}



int main()
{   
   lol v[4]={10,40,30,50};
   lol w[4]={5,4,6,3};
   lol W = 10 ;
   lol n = 4;
   cout<<knap(W,w,v,n); 


return 0;
}