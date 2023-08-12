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
        lol x, y;
        cin >> x >> y;
        lol mx = (long long)sqrtl(x + 1) - 1;
        lol ans = 0;
        for (lol i = 1; i <= mx; i++)
        {
            lol s = 1, e = y + 1;
            while (s != e - 1)
            {
                lol md = (s + e) / 2ll;
                if (md - 1 < i)
                {
                    s = md;
                }
                else
                {
                    if (i * 1ll * (md + 1) <= x)
                    {
                        s = md;
                    }
                    else
                        e = md;
                }
            }
            ans += max(s - i , 0ll);
        }
        cout << ans << '\n';
    }
}