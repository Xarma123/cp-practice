#include <bits/stdc++.h>
#define lol long long
using namespace std;
lol n;
lol len;
map<pair<lol, lol>, lol> mp;
lol solve(lol a[], lol l, lol r)
{
    lol lm = 0;
    if (l - 1 >= 0)
        lm = a[l - 1];
    lol rm = len;
    if (r + 1 < n)
        rm = a[r + 1];
    if (l > r)
    {
        return 0;
    }
    if (l == r)
        return rm - lm;
    if (mp.count({l, r}))
        return mp[{l, r}];

    lol ans = LONG_LONG_MAX;
    for (lol i = l; i <= r; i++)
    {
        ans = min(rm - lm + solve(a, l, i - 1) + solve(a, i + 1, r), ans);
    }
    return mp[{l, r}] = ans;
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while (1)
    {
        cin >> len;
        if (len == 0)
            break;
        mp.clear();
        cin >> n;
        lol a[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        cout << "The minimum cutting is " << solve(a, 0, n - 1) << '.' << endl;
    }

    return 0;
}