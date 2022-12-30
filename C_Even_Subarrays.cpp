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
        lol mp[2ll * n + 5];
        lol ans = 0;
        for (lol x = 0; x * 1ll * x <= 2ll * n; x++)
        {
            memset(mp, 0, sizeof(mp));
            mp[0] = 1;
            lol c = 0;
            for (lol i = 0; i < n; i++)
            {
                c ^= a[i];
                if ((c ^ (x * 1ll * x)) < 2ll * n + 5)
                    ans += mp[(c ^ (x * 1ll * x))];
                mp[c]++;
            }
        }
        ans = n * 1ll * (n + 1) / 2 - ans;
        cout << ans << endl;
    }

    return 0;
}