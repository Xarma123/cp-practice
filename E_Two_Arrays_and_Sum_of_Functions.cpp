#include <bits/stdc++.h>
#define lol unsigned long long
using namespace std;
bool c(lol a, lol b)
{
    return a > b;
}
int main()
{
    lol n;
    cin >> n;
    lol a[n];
    lol b[n];
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
        a[i] = (a[i] * 1ll * ((n - i) * (i + 1)));
    }
    for (lol i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    sort(a, a + n);
    sort(b, b + n, c);
    lol ans = 0;
    for (lol i = 0; i < n; i++)
    {
        ans = (ans + (a[i] % (998244353) * 1ll * b[i]) % (998244353)) % (998244353);
    }
    cout << ans;

    return 0;
}