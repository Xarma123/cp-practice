#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        

        long long lol n, m, x;
        cin >> n >> m;

        
            lol  k = 0 ;
           for (lol i = 32; i >=0; i--)
           {  if ( ((m+1) >>i&1)==((n)>>i&1 )) continue;
              if ( ((m+1) >>i&1)==0 && ((n)>>i&1)==1  )
              {  break;
                  
              } else
              {
                  k|= 1<<i;
              }
              

              
           
           
                
           
           
        }
        cout<<k<<endl;
    }
}
