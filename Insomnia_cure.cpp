#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{ 
  lol k , l, m, n , d;
   cin>>k>>l>>m>>n>>d;
   if(k==1||l==1||m==1||n==1)
   cout<<d;
   else
   { bool a[d]={0}; lol ans=0;
     for (lol i = k-1; i < d; i=i+k)
     {
          a[i]=1;
     }
     for (lol i = l-1; i < d; i=i+l)
     {
          a[i]=1;
     }
     for (lol i = m-1; i < d; i=i+m)
     {
          a[i]=1;
     } 
     for (lol i = n-1; i < d; i=i+n)
     {
          a[i]=1;
     } 
     for (lol i = 0; i < d; i++)
     {
          if(a[i]==1)
          ans++;
     } 
     cout<<ans;
     
       
   }
   

}