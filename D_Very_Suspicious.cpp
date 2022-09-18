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
        lol in = n / 2 + n % 2;

        lol x = ceill((2 + sqrtl(4 + 12 * 1ll * in)) / (long double)6);
        lol no = 3 * 1ll * x * 1ll * x - 2 * 1ll * x;
        lol ans = x + 2 * 1ll * (x - 1) + 1;
        x = 2 * 1ll * x - 1;
        if (no - x >= in)
        {
            no -= x;
            ans--;
            x--;
        }
        if (no - x >= in)
        {
            no -= x;
            ans--;
        }
        cout << ans << endl;
    }

    return 0;
}