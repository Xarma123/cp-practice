#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n;
    cin >> n;
    lol k;
    cin >> k;
    pair<lol, lol> a[n];
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i].first >> a[i].second;
    }
    sort(a, a + n);
    multiset<lol> x;
    lol ans = LONG_LONG_MIN;
    lol sum = 0;
    for (lol i = n - 1; i >= 0; i--)
    {
        x.insert(a[i].second);
        sum += a[i].second;
        while (x.size() > k)
        {
            sum -= (*x.begin());
            x.erase(x.begin());
        }
        if (x.size() == k)
        {
            ans = max(ans, sum * 1ll * a[i].first);
        }
    }
    cout << ans;

    return 0;
}
