#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, m, k;
    cin >> n >> m >> k;
    lol a[n];
    map<lol, lol> mp;
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
        mp[a[i]] = i;
    }
    lol ans = 0;
    while (m--)
    {
        lol c;
        cin >> c;
        ans += ceill((mp[c] + 1) / (long double)k);
        if (mp[c] != 0)
        {
            lol i = mp[c];
            swap(a[i], a[i - 1]);
            mp[c]--;
            mp[a[i]] = i;
        }
    }
    cout << ans;

    return 0;
}