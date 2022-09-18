#include <bits/stdc++.h>
#define lol long double
#define lol1 long long
using namespace std;
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        lol1 n;
        cin >> n;
        lol a[n];
        for (lol1 i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        lol ans = INT_MAX;
        for (lol1 i = 0; i < n - 1; i++)
        {

            lol1 l = i + 1;
            while (l < n)
            {
                lol tans = 0;
                lol d = a[l] - a[i];
                d = d / (long double)(l - i);

                lol c = a[i] + d;
                lol1 p = i + 1;
                while (p < n)
                {
                    if (c > 100 || c < -100)
                    {
                        tans = -1;
                        break;
                    }
                    if (a[p] != c)
                        tans++;
                    p++;
                    c += d;
                }
                if (tans == -1)
                   {
                       goto z;
                   }
                c = a[i] - d;
                p = i - 1;
                while (p >= 0)
                {
                    if (c > 100 || c < -100)
                    {
                        tans = -1;
                        break;
                    }
                    if (a[p] != c)
                        tans++;
                    p--;
                    c -= d;
                }
                if (tans == -1)
                 {
                    goto z;
                 }
                ans = min(ans, tans); 
                z:
                l++;
            }
        }
        if (n == 1 || n == 2)
            cout << 0 << endl;
        else
            cout << ans << endl;
    }

    return 0;
}