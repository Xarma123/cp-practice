#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long lol n ;
    cin>>n;
    long long lol a,min=INT_MAX,max=INT_MIN,min_n=0,max_n=0;
    for (long long lol i = 0; i < n; i++)
    {
        cin>>a; 
      
         if(max==a)
         {
             max_n++;
         }
         if(min==a)
         {
             min_n++;
         }
          if(a>max)
        { max=a; 
           max_n=1;
           
        }
         if(a<min)
         { min =a;
           min_n=1;
         } 
     
    }
     if(max==min)
     {
         cout<<0<<" "<<n*(n-1)/2;

     } 
     else
    {cout<<(max-min)<<" "; 
    cout<<(max_n)*(min_n);}
      

}