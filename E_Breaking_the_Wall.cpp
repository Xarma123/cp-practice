#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n;
    cin >> n;
    lol a[n];
    for (lol i = 0; i < n; i++)
        cin >> a[i];
    lol ans = LONG_LONG_MAX;
    for (lol i = 2; i < n; i++)
    {
        lol mn = min(a[i], a[i - 2]);
        lol mx = max(a[i], a[i - 2]);
        ans = min(ans, ((mn + 1) / 2) + ((mx - (mn % 2 > 0) + 1) / 2));
    }
    for (lol i = 1; i < n; i++)
    {
        lol mn = min(a[i], a[i - 1]);
        lol mx = max(a[i], a[i - 1]);
        if (mn * 2ll <= mx)
        {
            ans = min((mx - mn * 2ll + 1) / 2 + mn, ans);
        }
        else
        {
            ans = min(ans, (mn + mx + 2) / 3);
        }
    }
    sort(a, a + n);
    ans = min(ans, (a[0] + 1) / 2 + (a[1] + 1) / 2);
    cout << ans;

    return 0;
} 