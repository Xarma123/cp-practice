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
        if (n % (2050ll) == 0)
        {
            n /= 2050;
            lol ans = 0;
            while (n > 0)
            {
                ans += (n % 10);
                n /= 10ll;
            }
            cout << ans << '\n';
        }
        else
            cout << -1 << '\n';
    }
}