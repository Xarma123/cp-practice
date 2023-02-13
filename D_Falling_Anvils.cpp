#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol t;
    cin >> t;
    while (t--)
    {
        long double a, b;
        cin >> a >> b;
        // p >= 4q
        if (b == 0) 
        {
            cout << 1 << endl;
        }
        else if (a == 0)
        {
            cout << 0.5 << endl;
        }
        else
        {
            long double num = 0;
            num += b * a;
            if (a < b * 4)
            {
                num += a * b - ((2 * b - a / (long double)4) * (a) / (long double)2);
            }
            else
            {
                num += a * b - ((long double)2 * b * b);
            }

            cout << fixed << setprecision(10) << num / (long double)(((long double)2 * b) * a) << endl;
        }
    }
    /*
      |        4
      |
      |
      |----------------
       -2 -1 0 1 2
       y= 4*x

    */

    return 0;
}