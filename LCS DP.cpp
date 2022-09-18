#include<bits/stdc++.h>
using namespace std;
#define HareKrishna ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define mod 1000000007
#define ll long long int
#define pb push_back
const ll N=1e6;

vector<vector<ll>> dp(1e4, vector<ll> (1e4,0));

ll lcs(string a, string b)
{
    int m = a.length(), n = b.length();

    for (ll i=1; i<=m; i++)
    {
        for (ll j=1; j<=n; j++)
        {
            if (a[i-1] == b[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            }
           
            else  {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
 
  ll idx= dp[m][n];
  
  char str[idx+1];
  
  str[idx] = '\0'; 

  ll i = m, j = n;
  while (i > 0 && j > 0)
  {
    if (a[i-1] == b[j-1])
    {
      str[idx-1] = a[i-1];
      i--; j--; idx--;    
    }
    else if (dp[i-1][j] > dp[i][j-1])
      i--;
    else
      j--;
  }
  
  cout<<str<<endl;
  
  return dp[m][n];
}


void rk_d(){
    
    string a = "abcdef", b = "ace";
    cout<<lcs(a,b)<<endl;
    //dummy output: ace 3
}

int main(){
	
   HareKrishna;
   ll t;
  // cin>>t;
   t=1;
   
   while (t--){
   	
   	rk_d();
   	
   }
   
   return 0;
}
