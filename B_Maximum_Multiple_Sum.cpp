#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol t;
    cin >> t;
    while (t--)
    {
        lol n;
        cin >> n;
        lol mx = 0;
        lol ans = 0;
        for (lol i = 2; i <= n; i++)
        {
            lol v = i * 1ll * ((n / i) * 1ll * ((n / i) + 1)) / 2ll;
            if (v > mx)
            {
                mx = v;
                ans = i;
            }
        }
        cout << ans << '\n';
    }

    return 0;
}
