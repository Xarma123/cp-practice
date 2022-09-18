#include<bits/stdc++.h>
using namespace std;
#define fi(n) for(lol i = 0;i<n;i++)
#define fj(n) for(lol j = 0;j<n;j++)
#define ll long long lol
void solve(){
     ll a,b ;
     cin>>a>>b ;
     ll k = a+b ;
     ll s = min(a,b) ;
     k = k/4 ;
     cout<<min(k,s)<<endl;
}
int main(){
  ll t= 1 ;
  cin>>t ;
  while(t--){
    solve() ;
  }
}