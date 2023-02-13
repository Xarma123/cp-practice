#include <bits/stdc++.h>
#define lol long long
using namespace std;
lol r, x, y, xx, yy;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> r >> x >> y >> xx >> yy;
    long long v = sqrtl(powl(x - xx, 2) + powl(y - yy, 2));
    lol ans = (v / (2ll * r));
    if (v % (2ll * r))
        cout << ans + 1;
    else
    {
        if ((long long)powl(v, 2) == (long long)(powl(x - xx, 2) + powl(y - yy, 2)))
            cout << ans;
        else
            cout << ans + 1;
    }

    return 0;
}