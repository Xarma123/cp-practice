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
        lol n, y;
        cin >> n >> y;
        lol a[n];
        lol x = 0;
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
            x |= a[i];
        }
        bool ans = true;
        lol v = 0;
        for (lol i = 31; i >= 0; i--)
        {
            if ((x & (1ll << i)) && !(y & (1ll << i)))
            {
                ans = false;
            }
            else if (!(x & (1ll << i)) && (y & (1ll << i)))
            {
                v |= (1ll << i);
            }
        }
        if (ans)
            cout << v << '\n';
        else
            cout << -1 << '\n';
    }

    return 0;
}