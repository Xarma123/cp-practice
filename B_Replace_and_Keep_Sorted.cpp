#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, q, k;
    cin >> n >> q >> k;
    lol a[n];
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    lol c[n];
    for (lol i = 0; i < n; i++)
    {
        lol l = 0, r = k + 1;
        if (i + 1 < n)
        {
            r = a[i + 1];
        }
        if (i - 1 >= 0)
        {
            l = a[i - 1];
        }

        c[i] = r - l - 2;
        if (i)
            c[i] += c[i - 1];
    }
    while (q--)
    {
        lol l, r;
        cin >> l >> r;
        if (r - l + 1 == 1)
        {
            cout << k - 1 << '\n';
        }
        else
        {

            lol ans = c[r - 2] - c[l - 1];
            ans += a[l] - 2;
            ans += k - a[r - 2] - 1;
            cout << ans << '\n';
        }
    }
}