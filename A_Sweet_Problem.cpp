#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        lol r, g, b;
        cin >> r >> g >> b;
        if (r < b)
            swap(r, b);
        if (r < g)
            swap(r, g);
        if (b < g)
            swap(b, g);
        if (r == b)
        {
            if (b == g)
                cout << (r / 2) * 3 + r % 2 << endl;
            else
                cout << (g / 2) * 3 + g % 2 + b - g << endl;
        }
        else
        {
           
            lol ans = b - g;
            b -= ans;
            r -= ans;
            lol x = r - g;
          
            if (x >= g)
                ans += 2 * g;
            else
            {
                ans += (3 * x + (r - g)) / 2;
                g -= x;
                ans += (g / 2) * 3 + g % 2;
            }
            cout << ans << endl;
        }
    }

    return 0;
}