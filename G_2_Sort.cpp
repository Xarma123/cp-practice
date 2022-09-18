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
        lol n, k;
        cin >> n >> k;
        lol a[n];
        bool c[n];
        c[0] = true;
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
            if (i > 0)
            {
                if (a[i] * 2 > a[i - 1])
                {
                    c[i] = true;
                }
                else
                    c[i] = false;
            }
        }
        lol l = 0;
        lol ans = 0;
        for (lol i = 0; i <= n; i++)
        {
            if (i == n || c[i] == false)
            {
                lol v = i - l;
                ans += max(v - k, 0ll);
                l = i;
            }
        }

        cout << ans << endl;
    }

    return 0;
}