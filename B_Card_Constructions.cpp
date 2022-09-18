#include <bits/stdc++.h>
#define lol long double
using namespace std;
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        lol n;
        cin >> n;
        lol ans = 0;
        lol h = INT_MAX;
        while (h > 0)
        {

            h = floor((sqrt(1 + 24 * n) - 1) / 6.0);
            if (h)
                ans++;
            n -= h * (h + 1) + (h - 1) * (h) / 2;
        } 
        cout<<ans<<endl;

        /*
       if h = 3
       
        h*(h+1)+(h-1)*(h)/2  <=n 

        3*(h^2) + h -2*n <= 0 

       ( -1 + root(1 + 24n) )/6

       */
    }

    return 0;
}