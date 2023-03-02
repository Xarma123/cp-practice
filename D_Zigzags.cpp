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
        lol n;
        cin >> n;
        lol a[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        map<lol, lol> mp;
        lol ans = 0;
        for (lol i = 0; i < n; i++)
        {
            lol v = 0;
            for (lol j = i + 1; j < n; j++)
            {
                if (a[i] == a[j])
                {
                    ans += v;
                }
                v += mp[a[j]];
            }
            mp[a[i]]++;
        }
        cout << ans << '\n';
    }

    return 0;
}