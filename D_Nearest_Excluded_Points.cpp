#include"bits/stdc++.h"
using namespace std;
#define ll long long
void solve(){
     ll n ;
     cin>>n ;
     vector<ll> vk ;
     ll k = 1 ;
     ll s = pow(10,9) ;
     vk.push_back(k) ;
     for(int i = 0 ;i<n-1;i++){
       k += k +(k+1);
       if(k<=s){
          vk.push_back(k) ;
       }
       else{
         cout<<"NO"<<endl;
         return ;
       }
     }
     cout<<"YES"<<endl;
     for(auto c:vk){
       cout<<c<<' ' ;
     }
     cout<<endl;
  }
int main()
{
    //#ifndef ONLINE_JUDGE
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    //#endif
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t=1  ;
    cin>>t ;
    while(t--){
     solve() ;
    }
    
    
    return 0;
}