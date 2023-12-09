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
        lol n, k;
        cin >> n >> k;
        lol a[n];
        lol r = LONG_LONG_MIN;
        lol ev = 0;
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
            if (r != 0)
                r = max(r, (a[i] % k));
            if (a[i] % k == 0)
                r = 0;
            if (a[i] % 2 == 0)
                ev++;
        }
        if (k == 4)
        {
            if (ev > 1 || r == 0)
                cout << 0 << '\n';
            else
                cout << min(2 - ev, k - r) << '\n';
            continue;
        }
        if (r == 0)
            cout << 0 << '\n';
        else
            cout << k - r << '\n';
    }

    return 0;
}
