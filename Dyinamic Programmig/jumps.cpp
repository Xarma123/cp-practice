#include <bits/stdc++.h>
#define lol long double
using namespace std;
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        lol x;
        cin >> x;
        lol k = (sqrt(1 + 8 * x) - 1) / 2.0;
        if( (long double)((long long)k - (long double)k) ==0   ) 
        {
              cout<<k<<endl;
             
        } 
        else
        { 
            k = (long long)k+1;
              if(x==(k)*(k+1)/2-1)
              {
                  cout<<k+1<<endl;
              }
              else
              cout<<k<<endl;



        }
    }

    return 0;
}