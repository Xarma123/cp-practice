#include <bits/stdc++.h>
using namespace std;
#define lol long long
lol val(lol x, lol y)
{
    lol v = x * 1ll * (x + 1) + (x + y - 2) * 1ll * (x + y - 1) + x * 1ll * (x - 1);
    v /= 2ll;
    return v;
}
lol sumx(__int128 y1, __int128 y2, __int128 x)
{
    __int128 v = 0;
    v += (2 + x * x - x) * (y2 - y1 + 1);
    v += (2 * x - 3) * ((y2 * (y2 + 1) - y1 * (y1 - 1)) / 2);
    v += ((y2 * (y2 + 1) * (2 * y2 + 1)) - (y1 * (y1 - 1) * (2ll * y1 - 1))) / 6;
    v /= 2;
    return (long long)v;
}

lol sumy(__int128 x1, __int128 x2, __int128 y)
{
    __int128 v = 0;
    v += (x2 - x1 + 1) * (2 + y * y - 3 * y);
    v += (2 * y - 1) * ((x2 * (x2 + 1) - x1 * (x1 - 1)) / 2);
    v += ((x2 * (x2 + 1) * (2 * x2 + 1)) - (x1 * (x1 - 1) * (2 * x1 - 1))) / 6;
    v /= 2;
    return (long long)v;
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol t;
    cin >> t;
    while (t--)
    {
        lol x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        if (x1 == x2 || y1 == y2)
            cout << 1 << '\n';
        else
            cout << sumy(x1, x2, y1) + sumx(y1 + 1, y2, x2) - sumx(y1, y2, x1) - sumy(x1 + 1, x2, y2) + 1 << '\n';
    }
}