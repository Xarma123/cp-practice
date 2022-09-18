#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol n;
    cin >> n;
    lol a[n];
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    lol index = 0;
    for (lol i = 1; i < n; i++)
    {
        if (a[i] >= a[index])
        {
            a[++index]=a[i];
        }
        else
        {
            lol s=0;
            lol e= index;
            lol t=e;
            while (s<=e)
            {    
                lol m = (s+e)/2;
                if(a[m]<a[i])
                {
                    s=m+1;
                }
                else if(a[m]>a[i])
                {t=m;
                 e=m-1;

                }
                else
                {
                    t=m;
                    e=m-1;
                }
            } 
            
            
        }
    }

    return 0;
}