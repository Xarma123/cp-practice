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
    lol c = 0;
    while (t--)
    {

        lol p, f;
        cin >> p >> f;
        lol cs, cw;
        cin >> cs >> cw;
        lol s, w;
        cin >> s >> w;
        lol ans = LONG_LONG_MIN;
        for (lol i = 0; i <= cs; i++)
        {
            lol o = min(p / s, i);
            lol wo = min((p - o * 1ll * s) / w, cw);
            lol o2 = min(f / s, cs - i);
            lol w2 = min((f - o2 * 1ll * s) / w, cw - wo);
            ans = max(ans, o + o2 + wo + w2);
            w2 = min(f / w, cw - wo);
            o2 = min((f - w2 * 1ll * w) / s, cs - i);
            ans = max(ans, o + o2 + wo + w2);
        }
        cout << ans << '\n';
    }

    return 0;
}