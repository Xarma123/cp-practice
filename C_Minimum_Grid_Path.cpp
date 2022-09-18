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
        lol c[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> c[i];
        }

        lol mneven = c[0];
        lol mnodd = c[1];

        lol ans = LONG_LONG_MAX;
        lol sum = c[0];
        lol todd = 1;
        lol teven = 1;
        for (lol i = 1; i < n; i++)
        {
            sum += c[i];
            if (i != 1)
            {
                if (mneven > c[i] && i % 2 == 0)
                    mneven = c[i];
                if (mnodd > c[i] && i % 2 != 0)
                    mnodd = c[i];
                if (i % 2 == 0)
                    teven++;
                else
                    todd++;
            }
            ans = min(ans, sum + (n - teven) * mneven + (n - todd) * mnodd);
        }
        cout << ans << endl;
    }

    return 0;
}