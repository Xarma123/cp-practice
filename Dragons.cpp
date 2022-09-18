
#include<bits/stdc++.h>
using namespace std;

int main()
{
    lol s, n;
    cin >> s >> n;
    vector< pair <lol,lol> > vect;
    for (lol i = 0; i < n; i++)
    {
          lol a , b; cin>>a>>b;
          vect.push_back( make_pair(a,b) );
    } 
     sort(vect.begin(), vect.end()); lol i;
     for ( i = 0; i < n; i++)
     {  if(vect[i].first>=s)
         {cout<<"NO";
          break;

         }else{
             s+=vect[i].second;
         }
         
     } 
     if(i==n)
      cout<<"YES";
     
    
}