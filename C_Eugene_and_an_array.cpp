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
    map<lol, lol> mp;
    lol c = 0;
    mp[c] = -1;
    lol ans = 0;
    lol l = -2;
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
        c += a[i];
        if (mp.count(c))
        {
            l = max(l, mp[c]);
        }
        ans += l + 2;
        mp[c] = i;
    }
    cout << (n * 1ll * (n + 1) / 2ll) - ans;

    return 0;
}