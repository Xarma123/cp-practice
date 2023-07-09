#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        lol n;
        cin >> n;
        lol a[n];
        lol s = 0;
        bool av[(1ll << 8)];
        memset(av, false, sizeof(av));
        av[0] = true;
        lol ans = 0;
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
            s ^= a[i];
            for (lol j = 0; j < (1ll << 8); j++)
            {
                if (av[j])
                {
                    ans = max(ans, (s ^ j));
                }
            }
            av[s] = true;
        }
        cout << ans << '\n';
    }
}