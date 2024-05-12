#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol t;
    cin >> t;
    while (t--)
    {
        lol n, x;
        cin >> n >> x;
        lol a[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        lol ans = -1;

        for (lol b = 0; b < 33; b++)
        {

            lol val = -1;
            lol tans = 0;
            for (lol i = 0; i < n; i++)
            {
                if (val == -1)
                {
                    tans++;
                    val = a[i];
                }
                else
                    val ^= a[i];
                bool f = true;
                for (lol j = b; j < 33; j++)
                {
                    if ((x & (1ll << j)) == 0)
                    {
                        if ((val & (1ll << j)))
                            f = false;
                    }
                }
                if (b)
                {
                    if ((x & (1ll << (b - 1))))
                    {
                        if ((val & (1ll << (b - 1))))
                            f = false;
                    }
                    else
                        continue;
                }
                if (f)
                {
                    val = -1;
                }
            }
            if (val == -1)
            {
                ans = max(ans, tans);
            }
        }
        cout << ans << '\n';
    }

    return 0;
}
