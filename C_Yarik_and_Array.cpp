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
        lol n;
        cin >> n;
        lol a[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        lol c = 0;
        lol ans = LONG_LONG_MIN;
        for (lol i = 0; i < n; i++)
        {
            if (i == 0)
            {
                c += a[i];
                ans = max(ans, c);
            }
            else
            {
                if ((long long)abs(a[i - 1]) % 2 != (long long)abs(a[i]) % 2)
                {
                    c = max(a[i], a[i] + c);
                }
                else
                    c = a[i];
                ans = max(ans, c);
            }
        }
        cout << ans << '\n';
    }

    return 0;
}
