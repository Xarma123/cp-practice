#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol t;
    cin >> t;
    while (t--)
    {
        lol x, y, z, k;
        cin >> x >> y >> z >> k;
        lol ans = 0;
        for (lol i = 1; i <= x; i++)
        {
            for (lol j = 1; j <= y; j++)
            {
                lol v = i * 1ll * j;
                if (k % v == 0)
                {
                    lol zz = k / v;
                    if (zz <= z)
                    {
                        ans = max(ans, ((x - i + 1) * 1ll * (y - j + 1) * 1ll * (z - zz + 1)));
                    }
                }
            }
        }
        cout << ans << '\n';
    }

    return 0;
}
