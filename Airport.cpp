#include <iostream>
#include <string.h>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{

    lol n, m;
    cin >> n >> m;
    lol a[m], b[m]; lol seat=0;
    for (lol i = 0; i < m; i++)
    {
        cin >> a[i]; seat+=a[i];
        b[i] = a[i];
    }
    sort(a, a + m);
    lol k = 0;
    lol min = 0;
    for (lol i = 0; i < n; i++)
    {
        min += a[k];
        a[k]--;
        if (a[k] == 0)
            k++;
    }
    lol max = 0;
    if(seat==n){max=min;}
    else{
    k = 0;
    sort(b, b + m, greater<lol>());
    for (lol i = 0; i < n; i++)
    {
       
        max += b[k];
        b[k]--;
        if (k - 1 >= 0 && k + 1 < m)
        {
            if ((b[k] < b[k + 1] && k + 1 < m) && (b[k] < b[k - 1] && k - 1 >= 0))
            {
                if (b[k + 1] - b[k] > b[k - 1] - b[k])
                  {  k++;
                  }
                else
                   { k--; 
                   }
            }
        }
        else if (k - 1 >= 0)
        {
            if (b[k] < b[k - 1] && k - 1 >= 0)
            {
                k--; 
            
            }
        }
        else if (k + 1 < m)
        {
            if (b[k] < b[k + 1] && k + 1 < m)
            {
                k++;
            
            }
        }
    } 
    }
    cout << max << " " << min;
}