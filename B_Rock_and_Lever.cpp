#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol t;
    cin >> t;
    while (t--)
    {
        lol n;
        cin >> n;
        lol a[n];
        lol ans = 0;
        map<lol, lol> mp;
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
            for (lol j = 30; j >= 0; j--)
            {
                if ((a[i] & (1ll << j)))
                {
                    a[i] = (1ll << j);
                    break;
                }
            }
            ans += mp[a[i]];
            mp[a[i]]++;
        }
        cout << ans << '\n';
    }
}