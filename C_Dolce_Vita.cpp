#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    std::ios::sync_with_stdio(false);
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
        sort(a, a + n);
        lol c[n];
        c[0] = a[0];
        for (lol i = 1; i < n; i++)
        {
            c[i] = c[i - 1] + a[i];
        }
        lol ans = 0;
        lol l = 0;
        for (lol i = n - 1; i >= 0; i--)
        {
            if (x >= c[i])
            {
                lol d = ((x - c[i]) / (i + 1)) + 1;
                if (d > l)
                {
                    ans += (d - l) * 1ll * (i + 1);
                    l = d;
                }
            }
        }

        cout << ans << '\n';
    }
}