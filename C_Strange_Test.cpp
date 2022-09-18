#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        lol a, b;
        cin >> a >> b;
        lol ans = LONG_LONG_MAX;
        ans = min(ans, b - a);
        for (lol i = a; i < b; i++)
        {
            lol b1 = 0;
            for (lol j = 31; j >= 0; j--)
            {
                if ((i & (1 << j)))
                {
                    b1 += (1 << j);
                    if (!(b & (1 << j)))
                    {
                        break;
                    }
                }
                else
                {
                    if ((b & (1 << j)))
                    {
                        b1 += (1 << j);
                    }
                }
            }

            ans = min(ans, (i + (i | b1) + 1 - a - b));
        }

        cout << ans << endl;
    }

    return 0;
}