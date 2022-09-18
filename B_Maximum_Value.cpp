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
    {
        cin >> a[i];
    }
    sort(a, a + n);
    lol ans = LONG_LONG_MIN;
    for (lol i = 0; i < n; i++)
    {
        if (i > 0 && a[i] == a[i - 1])
            continue;
        int c = 0;
        for (lol j = 2 * a[i]; c == 0; j += a[i])
        {
            if (j >= a[n - 1])
                c++;

            auto it = lower_bound(a, a + n, j) - a;
            if (it == 0)
                continue;
            else
                it--;
            ans = max(ans, (a[it] % a[i]));
        }
    }
    cout << ans;

    return 0;
}