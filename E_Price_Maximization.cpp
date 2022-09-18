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
        lol n, k;
        cin >> n >> k;
        lol a[n];
        lol ans = 0;
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
            ans += a[i] / k;
            a[i] = a[i] % k;
        }
        sort(a, a + n);
        multiset<lol> mp;
        for (lol i = 0; i < n; i++)
        {
            if (a[i] == 0)
                continue;
            auto j = mp.lower_bound(k - a[i]);
            if (j != mp.end())
            {
                ans++;
                mp.erase(j);
            }
            else
                mp.insert(a[i]);
        }
        cout << ans << endl;
    }

    return 0;
}