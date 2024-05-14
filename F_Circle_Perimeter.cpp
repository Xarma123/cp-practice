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
        lol r;
        cin >> r;
        lol ans = 0;
        for (lol i = 1; i <= r; i++)
        {
            // x^2>= r*1ll*r-i*1ll*i
            lol s = -1, e = 1e9;
            while (s != e - 1)
            {
                lol m = (s + e) / 2ll;
                if (m == -1)
                {
                    s = m;
                }
                else if ((m * 1ll * m) >= (r * 1ll * r) - (i * 1ll * i))
                {
                    e = m;
                }
                else
                    s = m;
            }
            lol x1 = max(e, 1ll);

            s = 0, e = 1e9;
            while (s != e - 1)
            {
                lol m = (s + e) / 2ll;
                if ((m * 1ll * m) < ((r + 1) * 1ll * (r + 1)) - (i * 1ll * i))
                {
                    s = m;
                }
                else
                    e = m;
            }

            ans += s - x1 + 1;
        }
        ans *= 4ll;
        ans += 4;
        cout << ans << '\n';
    }

    return 0;
}
