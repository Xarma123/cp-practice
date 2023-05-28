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
    for (lol qqqw = 1; qqqw <= t; qqqw++)
    {
        cout << "Case #" << qqqw << ": ";
        lol m, r, n;
        cin >> m >> r >> n;
        lol x[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> x[i];
        }
        lol st = 0;
        bool f = true;
        lol ans = 0;
        bool set[n];
        memset(set, false, sizeof(set));
        while (st < m)
        {
            lol j = upper_bound(x, x + n, st + r) - x;
            j--;
            if (j < 0 || j >= n)
            {
                f = false;
                break;
            }
            if (set[j])
            {
                f = false;
                break;
            }
            set[j] = true;
            ans++;
            st = x[j] + r;
        }
        if (f)
            cout << ans << '\n';
        else
            cout << "IMPOSSIBLE\n";
    }

    return 0;
}