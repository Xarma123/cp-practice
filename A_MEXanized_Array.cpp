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
        lol n, k, x;
        cin >> n >> k >> x;
        if (n >= k && k - 1 <= x)
        {
            lol sum = (k - 1) * 1ll * (k) / 2ll;
            if (x <= k)
            {
                sum += (n - k) * 1ll * (k - 1);
            }
            else
            {
                sum += (n - k) * 1ll * (x);
            }
            cout << sum << '\n';
        }
        else
            cout << -1 << '\n';
    }
}