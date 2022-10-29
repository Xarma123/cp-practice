#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n;
    while (cin >> n)
    {
        if (n == 0)
            break;
        lol xmin = LONG_LONG_MIN, xmax = LONG_LONG_MAX;
        lol ymin = LONG_LONG_MIN, ymax = LONG_LONG_MAX;
        lol zmin = LONG_LONG_MIN, zmax = LONG_LONG_MAX;
        lol ans = -1;
        while (n--)
        {
            lol x, y, z, d;
            cin >> x >> y >> z >> d;
            if (x + d <= xmin || x >= xmax)
            {
                ans = 0;
            }
            xmin = max(xmin, x);
            xmax = min(xmax, x + d);

            if (y + d <= ymin || y >= ymax)
            {
                ans = 0;
            }
            ymin = max(ymin, y);
            ymax = min(ymax, y + d);

            if (z + d <= zmin || z >= zmax)
            {
                ans = 0;
            }
            zmin = max(zmin, z);
            zmax = min(zmax, z + d);
        }
        if (ans != 0)
            cout << (xmax - xmin) * 1ll * (ymax - ymin) * 1ll * (zmax - zmin) << endl;
        else
            cout << 0 << endl;
    }

    return 0;
}