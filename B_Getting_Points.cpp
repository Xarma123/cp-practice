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
        lol n, p, l, ts;
        cin >> n >> p >> l >> ts;
        lol s = 0, e = n;
        while (s != e - 1)
        {
            lol m = (s + e) / 2ll;
            lol v = (n - m) * 1ll * l + min((n - m) * 2ll, ((n - 1) / 7ll) + 1) * 1ll * ts;
            if (v >= p)
                s = m;
            else
                e = m;
        }
        cout << s << '\n';
    }

    return 0;
}
