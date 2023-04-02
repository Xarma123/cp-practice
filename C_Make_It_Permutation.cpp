#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol t;
    cin >> t;
    while (t--)
    {
        lol n, c, d;
        cin >> n >> c >> d;
        lol a[n];
        map<lol, lol> mp;
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
            mp[a[i]]++;
        }
        sort(a, a + n);
        lol ans = LONG_LONG_MAX;
        lol ex = 0;
        for (lol i = n - 1; i >= 0; i--)
        {
            lol v = (a[i] - (long long)mp.size()) * 1ll * d + (i - (long long)mp.size() + 1) * 1ll * c;

            ans = min(ans, v + ex);
            mp[a[i]]--;
            if (mp[a[i]] == 0)
                mp.erase(a[i]);
            ex += c;
        }
        cout << min(ans, n * 1ll * c + d) << '\n';
    }

    return 0;
}