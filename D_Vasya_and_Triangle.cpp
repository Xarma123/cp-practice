#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, m, k;
    cin >> n >> m >> k;
    lol v = n * 1ll * m;
    lol kk = k;
    lol g = __gcd(v, kk);
    kk /= g;
    if (kk == 1)
    {
        lol a = n / (__gcd(n, k));
        k /= (__gcd(n, k));
        lol b = m / (__gcd(m, k));
        cout << "YES" << '\n';
        cout << "0 0" << '\n';
        if (a < n)
            a += a;
        else
            b += b;
        cout << a << " " << 0 << '\n';
        cout << 0 << " " << b << '\n';
    }
    else if (kk == 2)
    {
        lol a = n / (__gcd(n, k));
        k /= (__gcd(n, k));
        lol b = m / (__gcd(m, k));
        cout << "YES" << '\n';
        cout << "0 0" << '\n';
        cout << a << " " << 0 << '\n';
        cout << 0 << " " << b << '\n';
    }
    else
        cout << "NO" << '\n';

    return 0;
}