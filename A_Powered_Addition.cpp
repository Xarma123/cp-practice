#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{

    lol t;
    cin >> t;
    while (t--)
    {
        lol n;
        cin >> n;
        lol a[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        lol ans = 0;
        lol mx = LONG_LONG_MIN;
        for (lol i = 0; i < n; i++)
        {

            if (a[i] < mx)
            {
                lol d = mx - a[i];
                lol x = ceil(log2l(1 + d));
         
                ans = max(ans, x);
            }
            mx = max(mx, a[i]);
        }
        cout << ans << endl;
    }

    return 0;
}