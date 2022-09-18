#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        lol n, l, r, k;
        cin >> n >> l >> r >> k;
        lol a[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        sort(a, a + n);
        lol i = lower_bound(a, a + n, l) - a;
        lol ans = 0;
        lol cp = 0;
        for (; i < n; i++)
        {
            if (cp <= k)
            {
                if (a[i] <= r)
                {
                    if (cp + a[i] <= k)
                    {
                        cp += a[i];

                        ans++;
                    }
                    else
                        break;
                }
                else
                {
                    break;
                }
            }
            else
            {
                break;
            }
        }
        cout << ans << endl;
    }

    return 0;
}