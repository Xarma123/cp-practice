#include<bits/stdc++.h>
using namespace std ;
#define ll long long
void solve(){
     ll n ;
     cin>>n ;
     ll sq = 2 ;
     ll cube = 2 ;
     ll coun = 1 ;
     while(sq*sq<=n)
     {
         sq++;
         coun++;
     }
     while(cube*cube*cube<=n){
         cube++;
         coun++;
     }
     sq = 2 ;
     cube = 2 ;
     while(cube*cube*cube<=n){
         if(sq*sq==cube*cube*cube)
          {
              coun--;
              sq++;
              cube++;
              continue ;
          }
         else if(sq*sq<cube*cube*cube){
             sq++;
         }
         else{
             cube++;
             sq++;
         }

     }
     cout<<coun<<endl;
}


int main(){
    lol k = 1 ;
    cin>>k;
    while(k--){
        solve() ;
    }
}