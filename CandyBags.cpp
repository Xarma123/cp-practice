#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    lol n;
    cin >> n;
    lol a[(n * n)];
    for (lol i = 1; i <= (n * n); i++)
    {
        a[i - 1] = i;
    }

        for (lol j = 0; j < n; j++)
    {
        /* code */
    
    
  lol  m, ans=0,max=n*n*(n*n+1)/2;

  
  for (lol i = n; i >0; i--)
  {  
        max = (max-ans)/i;
      cout<<" ("<<max<<" )";
       lol s = 0, e = n * n - 1 ;
    while (s <= e)
    {
        m = (s + e) / 2;
        if (a[m] == max)
        {
            ans = a[m];
            a[m] = 0;
            break;
        }
        else if (a[m] < max)
        {
            
            ans = a[m];
               if(s==e)a[m]=0;
            s = m + 1;
        }
        else
        {
            e = m - 1;
        }
    }
    cout << ans <<" ";  sort(a,a+n*n);
    max=max*i;

  } 
    cout<<endl;
    }
    
}