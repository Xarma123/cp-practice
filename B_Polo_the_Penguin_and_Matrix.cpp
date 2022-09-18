#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol n, m, d;
    cin >> n >> m >> d;
    lol a[n * m];

    for (lol i = 0; i < n * m; i++)
    {
        cin >> a[i];
    }
    lol ans = LONG_LONG_MAX;
    sort(a, a + m * n);

    for (lol i = m * n / 2;; i = m * n / 2 + 1)
    {

        bool f = true;
        lol c = 0;
        for (lol i1 = 0; i1 < n * m; i1++)
        {

            if (abs(a[i-1] - a[i1]) % d != 0)
            {
                f = false;
                break;
            }
            else
                c += abs(a[i-1] - a[i1]) / d;
        }
        if (f)
            ans = min(ans, c);
        if (i == m * n / 2 + 1)
            break;
    }
    if (ans == LONG_LONG_MAX)
        cout << -1;
    else
        cout << ans;

    return 0;
}