#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n;
    cin >> n;
    lol a[n];
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    lol m;
    cin >> m;
    lol b[m];
    for (lol i = 0; i < m; i++)
    {
        cin >> b[i];
    }
    sort(a, a + n);
    sort(b, b + m);
    lol ans = LONG_LONG_MIN;
    lol q = 0;
    for (lol i = 0; i < n; i++)
    {
        lol d = a[i] - 1;

        lol j = upper_bound(b, b + m, d) - b;
        if (3ll * (n - i) + 2ll * (i) - (3ll * (m - j) + 2ll * j) > ans)
        {
            ans = 3ll * (n - i) + 2ll * (i) - (3ll * (m - j) + 2ll * j);
            q = d;
        }
    }
    if (2ll * n - 2ll * m > ans)
    {
        ans = 2ll * n - 2ll * m;
        q = LONG_LONG_MAX;
    }
    lol j = upper_bound(a, a + n, q) - a;
    cout << 3ll * (n - j) + 2ll * j << ':';
    j = upper_bound(b, b + m, q) - b;
    cout << 3ll * (m - j) + 2ll * j;

    return 0;
}