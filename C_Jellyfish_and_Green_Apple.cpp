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
        lol n, m;
        cin >> n >> m;
        if (n % m == 0)
            cout << 0 << '\n';
        else if ((m & (m - 1)))
        {
            cout << -1 << '\n';
        }
        else
        {
            lol r = n % m;
            lol ans = 0;
            for (lol i = 0; i < 32; i++)
            {
                if ((r & (1ll << i)))
                {
                    ans += m - (1ll << i) ;
                }
            }
            cout << ans << '\n';
        }
    }
}