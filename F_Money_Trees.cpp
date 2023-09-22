#include <bits/stdc++.h>
using namespace std;
#define lol long long
lol n, k;
lol a[200005];
lol h[200005];
lol solve(lol l, lol r)
{
    lol j = l;
    lol tot = 0;
    lol ans = 0;
    for (lol i = l; i < r; i++)
    {
        if (j < i)
            j = i;
        while (j < r && tot + a[j] <= k)
        {
            tot += a[j];
            j++;
        }
        ans = max(ans, j - i);
        if (j != i)
            tot -= a[i];
    }
    return ans;
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol t;
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (lol i = 0; i < n; i++)
        {
            cin >> h[i];
        }
        lol ans = 0;
        for (lol i = 0; i < n; i++)
        {
            lol j = i + 1;
            while (j < n && (h[j - 1] % h[j] == 0))
            {
                j++;
            }
            ans = max(ans, solve(i, j));
            i = j - 1;
        }
        cout << ans << '\n';
    }
}