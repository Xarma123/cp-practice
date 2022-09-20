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
        lol n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        lol c[n + 1];
        c[0] = 0;
        for (lol i = 1; i <= n; i++)
        {
            c[i] = c[i - 1] + (s[i - 1] - '0');
        }
        lol ans = 0;
        for (lol i = 1; i <= n; i++)
        {
            if (s[i - 1] == '1')
                ans += c[min(i + k, n)] - c[max(i - k - 1, 0ll)];
        }
        lol sw = n * 1ll * n;
        lol g = __gcd(ans, sw);
        cout << ans / g;
        cout << '/';
        cout << sw / g;
        cout << endl;
    }

    return 0;
}