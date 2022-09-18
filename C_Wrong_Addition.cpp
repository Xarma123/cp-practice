#include<bits/stdc++.h>
using namespace std ;
#define ll long long
lol k(char a){
    return a - '0' ;
}
void solve(){
     string a , s ;
     cin>>a>>s ;
     lol b = a.size() ;
     lol c = s.size() ;
     lol arr[c] = {0} ;
     lol coun = 0 ;
     lol ai = b-1 ;
     lol si = c-1;
     while(si>=0){
         if(ai==-1){
             arr[coun] = k(s[si]) ;
             coun++;
             si--;
         }
         else if(s[si]>=a[ai]){
            arr[coun] = k(s[si])-k(a[ai]) ;
            coun++;
            ai--;
            si--; 
         }
         else if(s[si]<a[ai])
          {
              if(s[si-1]=='1')
              {
                  arr[coun] = 10 - (k(a[ai])-k(s[si])) ;
                  ai--;
                  si -= 2 ;
                  coun++;
              }
              else {
                  cout<<-1<<endl;
                  return ;
              }
          }
          if(si==-1&&ai>=0)
           {
                cout<<-1<<endl;
                return ;
           }

     }
     lol flag = 0 ;
     for(lol i = coun-1;i>=0;i--){
     if(arr[i]!=0)
     flag = 1 ;
     if(flag==0){
         if(arr[i]==0)
          continue ;
         else
         cout<<arr[i] ;
     }
     else cout<< arr[i] ;}
     cout<<endl;
}


int main(){
    lol k = 1 ;
    cin>>k;
    while(k--){
        solve() ;
    }
}