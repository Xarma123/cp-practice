#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        lol l, r, m;
        cin >> l >> r >> m;
        bool f = true;
        lol i;
        lol x;
        for (i = l; i <= r; i++)
        {
            x = m % (i);
            if (x >= 0 && x <= (r - l))
            {
                if (m - x > 0)
                    break;
            }
            x = i - x;
            if (x >= 0 && x <= (r - l))
            {
                if (m + x > 0)
                {
                    f = false;
                    break;
                }
            }
        }
        if (f)
            cout << i << " " << x + l << " " << l << endl;
        else
        {
            cout << i << " " << l << " " << l + x << endl;
        }
    }

    return 0;
}