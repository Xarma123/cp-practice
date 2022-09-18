
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;


int main()
{
    long long  t;
    cin >> t;
    for (long long  k = 0; k < t; k++)
    {

        long long  n, x;
        cin >> n >> x;
       long long  a[n];
       
   
        for (long long  i = 0; i < n; i++)
        {
            cin >> a[i];
          
        }
        sort(a, a + n);
        long long  c = 0;
        long long  no=1;
        long long  sum=0;
            for (long long i = n - 1; i >= 0; i--)
            {   sum+=a[i];
            if ( (sum/(no*1.0) )>=x)
            {   c++; no++;
                
            }else
            {
                break;
            }
            
            
               
                
            }
            cout << c << endl;
        
    }
}