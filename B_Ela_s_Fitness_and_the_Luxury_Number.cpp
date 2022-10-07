#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol t;
    cin >> t;
    while (t--)
    {
        lol l, r;
        cin >> l >> r;
        lol s = (long long)sqrtl(l);
        lol ans = 0;
        lol mn = l;
        lol mx = min(s * 1ll * (s + 2), r);
        ans += mx / s - (mn / s + ((mn % s) > 0)) + 1;
        if (mx == r)
        {
            cout << ans << endl;
        }
        else
        {
            lol s1 = (long long)sqrtl(r);
            ans += 3 * 1ll * (s1 - s - 1);
            mn = s1 * 1ll * s1;
            mx = r;
            ans += mx / s1 - (mn / s1 + ((mn % s1) > 0)) + 1;
            cout << ans << endl;
        }
    }

    return 0;
}