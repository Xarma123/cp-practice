#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, l, r, ql, qr;
    cin >> n >> l >> r >> ql >> qr;
    lol w[n];
    lol t = 0;
    lol c[n];
    for (lol i = 0; i < n; i++)
    {
        cin >> w[i];
        t += w[i];
        c[i] = w[i];
        if (i)
            c[i] += c[i - 1];
    }
    lol ans = LONG_LONG_MAX;
    for (lol i = 0; i <= n; i++)
    {
        lol v = 0;
        if (i)
            v += l * 1ll * (c[i - 1]);
        v += r * 1ll * (t - (i > 0 ? c[i - 1] : 0));
        if (i > n - i + 1)
        {
            v += ql * 1ll * (i - n + i - 1);
        }
        else if (n - i > i + 1)
        {
            v += qr * 1ll * (n - i - i - 1);
        }
        ans = min(ans, v);
    }

    cout << ans;

    return 0;
}