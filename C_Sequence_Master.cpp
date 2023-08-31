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
        lol a[2ll * n];
        lol sum = 0;
        for (lol i = 0; i < 2ll * n; i++)
        {
            cin >> a[i];
            sum += abs(a[i]);
        }
        if (n == 1)
        {
            cout << ((long long)abs(a[0] - a[1])) << '\n';
        }
        else if (n == 2)
        {
            lol s = 0;
            for (lol i = 0; i < 2ll * n; i++)
            {
                s += abs(a[i] - 2ll);
            }
            lol ans = min(sum, s);
            s = 0;
            for (lol i = 0; i < 2ll * n; i++)
            {
                s += abs(a[i] + 1);
            }
            for (lol i = 0; i < 2ll * n; i++)
            {
                ans = min(ans, s - (long long)abs(a[i] + 1) + (long long)abs(a[i] - n));
            }
            cout << ans << '\n';
        }
        else if (n % 2 == 0)
        {
            lol s = 0;
            for (lol i = 0; i < 2ll * n; i++)
            {
                s += abs(a[i] + 1);
            }
            lol ans = sum;
            for (lol i = 0; i < 2ll * n; i++)
            {
                ans = min(ans, s - (long long)abs(a[i] + 1) + (long long)abs(a[i] - n));
            }
            cout << ans << '\n';
        }
        else
            cout << sum << '\n';
    }
}