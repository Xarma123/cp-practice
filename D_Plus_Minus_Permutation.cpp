#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol t;
    cin >> t;
    while (t--)
    {
        lol n, x, y;
        cin >> n >> x >> y;
        lol mxx = n / x;
        lol mxy = n / y;
        lol z = x * 1ll * y / __gcd(x, y);
        lol mxz = n / z;
        mxx -= mxz;
        mxy -= mxz;
        cout << (mxx * 1ll * (2ll * n - mxx + 1) / 2ll - mxy * 1ll * (2ll + mxy - 1) / 2ll) << '\n';
    }
}