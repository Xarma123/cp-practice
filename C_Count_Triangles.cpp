#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol a, b, c, d;
    cin >> a >> b >> c >> d;
    lol ans = 0;
    for (lol k = a; k <= b; k++)
    {
        if (b - 1 + k >= c)
        {
            ans += (min(b - 1 + k, d) - c + 1) * 1ll * (c - b + 1);
        }
        lol l = max(b + k, c);
        lol r = min(c + k - 1, d);
        if (l <= r)
        {
            lol q = c - l + k;
            lol q2 = c - r + k;
            q2--;
            ans += (q * 1ll * (q + 1) - q2 * 1ll * (q2 + 1)) / 2;
        }
    }
    cout << ans;

    return 0;
}