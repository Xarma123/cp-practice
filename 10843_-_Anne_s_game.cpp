#include <bits/stdc++.h>
#define lol long long
using namespace std;
lol m = 2000000011;
lol pmod(lol a, lol p)
{
    lol r = 1;
    while (p)
    {
        if ((p & 1))
            r = r * 1ll * a % m;
        a = a * 1ll * a % m;
        p /= 2;
    }
    return r;
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n;
    cin >> n;

    lol c = 1;
    while (n--)
    {
        lol a;
        cin >> a;
        // a^(a-2)

        cout << "Case #" << c << ": " << pmod(a, a - 2) << endl;
        c++;
    }

    return 0;
}