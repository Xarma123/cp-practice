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
        lol ans = 0;
        for (lol i = n - 2; i >= 0; i--)
        {
            if (a[i] > a[i + 1])
            {
                lol mx = 0;
                for (lol j = 0; j <= i; j++)
                {
                    mx = max(mx, a[j]);
                }
                ans += mx;
                break;
            }
        }
        cout << ans << '\n';
    }
}