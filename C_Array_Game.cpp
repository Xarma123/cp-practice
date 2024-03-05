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
        lol n, k;
        cin >> n >> k;
        lol a[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        if (k == 1)
        {
            sort(a, a + n);
            lol mn = LONG_LONG_MAX;
            for (lol i = 1; i < n; i++)
            {
                mn = min(mn, a[i] - a[i - 1]);
                mn = min(mn, a[i]);
            }
            mn = min(mn, a[0]);
            cout << mn << '\n';
        }
        else if (k >= 3)
        {
            cout << 0 << '\n';
        }
        else
        {
            sort(a, a + n);
            lol mn = LONG_LONG_MAX;

            for (lol i = 1; i < n; i++)
            {
                mn = min(mn, a[i] - a[i - 1]);
                mn = min(mn, a[i]);
            }

            mn = min(mn, a[0]);

            for (lol i = 0; i < n; i++)
            {
                lol k = -1;
                for (lol j = 1; j < n; j++)
                {
                    while (k + 1 < j && a[j] - a[k + 1] >= a[i])
                    {
                        k++;
                    }
                    if (k >= 0 && k < j)
                    {
                        mn = min((a[j] - a[k]) - a[i], mn);
                    }
                    if (k + 1 >= 0 && k + 1 < j)
                    {
                        mn = min(a[i] - (a[j] - a[k + 1]), mn);
                    }
                }
            }
            cout << mn << '\n';
        }
    }

    return 0;
}
