#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, m, q;
    cin >> n >> m >> q;
    lol g = __gcd(n, m);
    while (q--)
    {
        lol sx, sy, ex, ey;
        cin >> sx >> sy >> ex >> ey;
        lol x;
        lol d;
        if (sx == 1)
            d = n / g;
        else
            d = m / g;
        x = ((sy + d - 1) / d);

        lol y;
        if (ex == 1)
            d = n / g;
        else
            d = m / g;
        y = ((ey + d - 1) / d);
        if (x == y)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}