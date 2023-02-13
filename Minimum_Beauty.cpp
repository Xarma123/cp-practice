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
        lol n;
        cin >> n;
        lol a[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        sort(a, a + n);
        lol ans = LONG_LONG_MAX;
        for (lol i = 0; i < n - 2; i++)
        {
            for (lol j = i + 1; j < n - 1; j++)
            {
                lol v = 2ll * a[j] - a[i];
                lol k = lower_bound(a + j + 1, a + n, v) - a;
                if (k < n)
                {
                   
                    ans = min(ans, abs(a[k] - v));
                }
                if (k > j + 1)
                {
                    k--;
                  
                    ans = min(ans, abs(a[k] - v));
                }
            }
        }
        cout << ans << '\n';
    }

    return 0;
}