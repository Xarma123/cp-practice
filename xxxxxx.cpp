#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string A;
    cin>>A;
    int dp[A.size()][A.size()];
 bool dp2[A.size()][A.size()];
 for(int i=0;i<A.size();i++)
 {
     for(int j=0;j<A.size();j++)
     {
         dp[i][j]=0;
         dp2[i][j]=false;
     }
 }
  for(int k=0;k<A.size();k++)
  {
      for(int i=0,j=k;i<A.size()&&j<A.size();i++,j++)
      {
          if(i==j)
          {dp[i][j]=1;
          dp2[i][j]=true;}
          else if(i==j-1)
          {   
              dp[i][j]=2;
              if(A[i]==A[j])
              {dp[i][j]++;
            dp2[i][j]=true;
              }
          }
          else
          { 
              if(dp2[i+1][j-1]&&A[i]==A[j])
              dp2[i][j]=true;
             
             dp[i][j]=dp[i+1][j]+dp[i][j-1]-dp[i+1][j-1];
             if(dp2[i][j])
             dp[i][j]++;
          } 
           cout<<dp[i][j]<<endl;
      }
  } 
  cout<<dp[A.size()-1][A.size()-1];

    return 0;
}