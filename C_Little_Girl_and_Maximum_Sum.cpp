#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, q;
    cin >> n >> q;
    lol a[n];
    lol c[n];
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
        c[i] = 0;
    }
    while (q--)
    {
        lol l, r;
        cin >> l >> r;
        l--;
        c[l]++;
        if (r < n)
            c[r]--;
    }
    for (lol i = 1; i < n; i++)
    {
        c[i] += c[i - 1];
    }
    sort(c, c + n);
    sort(a, a + n);
    lol ans = 0;
    for (lol i = 0; i < n; i++)
    {
        ans += a[i] * 1ll * c[i];
    }
    cout << ans;

    return 0;
}