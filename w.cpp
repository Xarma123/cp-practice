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
    lol k;
    cin >> k;
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    map<lol, lol> mp;
    lol s = 0;
    for (lol i = 0; i < k; i++)
    {
        mp[a[i]]++;
        s += a[i];
    }
    lol ans = LONG_LONG_MIN;
    if (mp.size() == k)
        ans = max(ans, s);

    for (lol i = k; i < n; i++)
    {
        s += a[i];
        s -= a[i - k];
        mp[a[i]]++;
        mp[a[i - k]]--;
        if (mp[a[i - k]] == 0)
            mp.erase(a[i - k]);
        if (mp.size() == k)
            ans = max(ans, s);
    }
    cout << ans;

    return 0;
}