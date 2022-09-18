#include <bits/stdc++.h>
#define lol long double
using namespace std;
int main()
{
    long long  t;
    cin >> t;
    while (t--)
    {
        long long  n, k;
          cin >> n >> k;
         long long a[n];
         lol p =1;
        for (long long  i = 0; i < n; i++)
        {
            cin >> a[i]; 
            a[i]= (long long)pow(10,a[i]);
            p = p*a[i]; 
           
        } 
         lol s = k*p,s2=0;
         for (long long i = n-1; i >=0; i--)
         {  lol x = p/a[i];
              lol t = x;
             
            for (long long  j = n-1; j>i; j--)
            { 
                t= t - (long double)x/(a[j]);
               
            } 
        s2+= t;
             
         } 
         cout<<s/s2<<endl;
         
    }

    return 0;
}