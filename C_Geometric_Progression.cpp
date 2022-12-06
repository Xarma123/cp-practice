#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, k;
    cin >> n >> k;
    lol a[n];
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    map<lol, lol> f;
    lol l[n];
    for (lol i = 0; i < n; i++)
    {
        if (a[i] % k == 0)
        {
            l[i] = f[a[i] / k];
        }
        else
            l[i] = 0;
        f[a[i]]++;
    }
    f.clear();
    lol r[n];
    for (lol i = n - 1; i >= 0; i--)
    {
        r[i] = f[a[i] * 1ll * k];
        f[a[i]]++;
    }
    lol ans = 0;
    for (lol i = 0; i < n; i++)
    {
        ans += l[i] * 1ll * r[i];
    }
    cout << ans;

    return 0;
}