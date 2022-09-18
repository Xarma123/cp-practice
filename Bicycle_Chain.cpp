#include <bits/stdc++.h>
using namespace std;
int main()
{ 
    lol n ;   
    cin>>n; lol a[n];
    for (lol i = 0; i < n; i++)
    {
      cin>>a[i];
    }
     lol m ;  
    cin>>m; lol b[m];
    for (lol i = 0; i < m; i++)
    {
      cin>>b[i];
    } 
 lol ans = 0 ;lol max =0;

    for (lol i = 0; i < m; i++)
    {
          for (lol j = 0; j < n; j++)
          {   if(b[i]%a[j]==0) 
               {   
                   if(b[i]/a[j]==max)
                    {  ans++;

                    } 
                    else if(b[i]/a[j]>max)
                    {  ans=1;
                       max=b[i]/a[j];

                    }

               }
              
          }
          
    }
    
     cout<<ans;
    
}