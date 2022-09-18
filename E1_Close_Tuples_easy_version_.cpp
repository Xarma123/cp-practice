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
        sort(a, a + n);
        lol ans = 0;
        for (lol i = 0; i < n; i++)
        {

            lol j = upper_bound(a, a + n, a[i] + 2) - a;

            if (j == n)
            {
                ans += (j - i - 1) * 1ll * (j - i - 2) / (long long)2;
            }
            else
            {
                while (a[j] > a[i] + 2)
                {
                    j--;
                    if (j == i)
                        break;
                }

                ans += (j - i) * 1ll * (j - i - 1) / (long long)2;
            }
        }
        cout << ans << endl;
    }

    return 0;
}