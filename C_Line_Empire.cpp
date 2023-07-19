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
        lol n, a, b;
        cin >> n >> a >> b;
        lol x[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> x[i];
        }
        lol suf[n];
        for (lol i = n - 1; i >= 0; i--)
        {
            if (i == n - 1)
                suf[i] = x[i];
            else
                suf[i] = x[i] + suf[i + 1];
        }
        lol ans = b * 1ll * suf[0];
        lol l = 0;
        lol lc = 0;
        for (lol i = 0; i < n; i++)
        {
            lc = (a + b) * 1ll * (x[i] - l) + lc;
            l = x[i];
            lol cs = lc;
            if (i + 1 < n)
            {
                cs += (suf[i + 1] - x[i] * 1ll * (n - i - 1)) * 1ll * b;
            }
            ans = min(ans, cs);
        }
        cout << ans << '\n';
    }

    return 0;
}