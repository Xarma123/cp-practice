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
        lol n;
        cin >> n;
        lol a[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        if (n == 1)
        {
            cout << max(0ll, a[0]) << '\n';
            continue;
        }
        lol ans = 0;
        lol j = n;
        for (lol i = 0; i < n; i++)
        {
            if (j == n)
            {
                if (a[i] >= 0 && (i % 2 == 0))
                {
                    j = i;
                    ans += a[i];
                }
            }
            else
            {
                if (a[i] >= 0)
                    ans += a[i];
            }
        }

        lol sum = 0;
        for (lol i = 0; i < j; i++)
        {
            if (a[i] >= 0)
                sum += a[i];
        }
        if (j > 0)
        {
            if (a[1] >= 0)
                ans += max(a[0] + sum, sum - a[1]);
            else
                ans += sum;
        }

        cout << ans << '\n';
    }
}