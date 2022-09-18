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
    lol v = (a * 1ll * d - c * 1ll * b);
    lol v2 = a * 1ll * d;
    if (v < 0)
        v = -v, v2 = c * 1ll * b;
    lol g = __gcd(v, v2);
    v /= g;
    v2 /= g;
    cout << v << "/" << v2;

    return 0;
}