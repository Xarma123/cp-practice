#include <bits/stdc++.h>
#define lol long long
using namespace std;

int main()
{
    lol n;
    cin >> n;
    lol a[n];
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n);
    lol f1 = 0;
    for (lol i = 0; i < n; i++)
    {
        f1 += abs(a[i] - 1);
    }
    lol u = f1 + a[n - 1];
    lol ans = LONG_LONG_MAX;
    for (lol i = 1; pow(i, n - 1) <= u; i++)
    {
        lol x = 1;
        lol c = 0;
        for (lol j = 0; j < n; j++)
        {
            c += abs(x - a[j]);
            x = x * 1ll * i;
        }

        ans = min(ans, c);
    }
    cout << ans;

    return 0;
}