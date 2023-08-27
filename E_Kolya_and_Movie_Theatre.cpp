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
        lol n, m, d;
        cin >> n >> m >> d;
        lol a[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        multiset<lol> x;
        lol s = 0;
        lol p[n];
        for (lol i = 0; i < n; i++)
        {
            if (a[i] > 0)
            {
                x.insert(a[i]);
                s += a[i];
                if ((long long)x.size() > m - 1)
                {
                    s -= (*x.begin());
                    x.erase(x.begin());
                }
            }
            p[i] = s;
        }
        lol ans = 0;
        for (lol i = 0; i < n; i++)
        {
            if (i)
            {
                ans = max(ans, p[i - 1] + a[i] - (i + 1) * 1ll * d);
            }
            else
                ans = max(ans, a[i] - d);
        }
        cout << ans << '\n';
    }
}