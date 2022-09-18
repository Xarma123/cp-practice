#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol q;
    cin >> q;
    while (q--)
    {
        lol ans = 0;
        lol c, m, x;
        cin >> c >> m >> x;
        lol mn = min(c, min(m, x));
        ans += mn;
        c -= mn;
        m -= mn;
        x -= mn;

        if (c < m)
            swap(c, m);
        if (c != 0 && m != 0)
        {
            lol k = min(c - m, min(c / 2, m));
            ans += k;
            c = c - 2 * 1ll * k;
            m = m - k;
            if (c != 0 && m != 0)
            {
                ans += 2 * 1ll * (c / 3);
                c = c % 3;
                if (c == 2)
                    ans++;
            }
        }
        cout << ans << endl;
    }

    return 0;
}