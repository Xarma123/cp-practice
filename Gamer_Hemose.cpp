#include<bits/stdc++.h>
using namespace std;
int main()
{
   long long t;
   cin>>t;
    while(t--)
    { 
        long long  n , H,max1=INT_MIN,max2=INT_MIN;
        cin>>n>>H; 
        while(n--)
        {  long long t;
          cin>>t; 
          if(t==max1)
          {
              max2=t;
          }
          else if(t>max1)
          {   max2=max1;
              max1=t; 

          }
          else if(t>max2)
          {
              max2=t;
          }


        }
        long long ans=0; 
          long long r = H % (max1+max2); long long t= H/(max1+max2);
          if(r==0)
          {
              ans+= 2*t;
          }
          else
          {
              ans+=2*t;
              H-= t*(max1+max2);
              if(H>0)
            {  H-=max1;ans++;

            }
              if(H>0)
            {  H-=max2;ans++;

            }
              

          } cout<<ans<<endl;
    }
          

return 0;
}