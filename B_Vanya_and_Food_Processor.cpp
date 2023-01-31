#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, h, k;
    cin >> n >> h >> k;
    lol a[n];
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    lol c = 0;
    lol ans = 0;
    for (lol i = 0; i < n; i++)
    {
        c += a[i];
        if (i + 1 < n && c + a[i + 1] > h)
        {
            lol q = ceill((a[i + 1] - h + c) / (long double)k);
            ans += q;
            c -= q * 1ll * k;
            c = max(c, 0ll);
        }
        else if (i + 1 >= n)
        {
            ans += ceill(c / (long double)k);
        }
    }
    cout << ans;

    return 0;
}