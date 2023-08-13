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
        lol ans = LONG_LONG_MIN;
        for (lol i = 1; i <= n; i++)
        {

            lol a[n];
            for (lol k = 0; k < n; k++)
            {
                a[k] = k + 1;
            }
            reverse(a + i - 1, a + n);
            for (lol k = 0; k < n; k++)
            {
                a[k] = a[k] * 1ll * (k + 1);
            }

            sort(a, a + n);
            lol sum = 0;
            for (lol k = 0; k < n - 1; k++)
            {
                sum += a[k];
            }
            ans = max(ans, sum);
        }
        cout << ans << '\n';
    }
}