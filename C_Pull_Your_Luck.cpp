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
        lol n, x, p;
        cin >> n >> x >> p;
        lol r = x % n;
        r = n - r;
        r %= n;
        lol i;
        bool ans = false;
        for (i = 1; i <= 2ll * n && i <= p; i++)
        {
            lol v = i * 1ll * (i + 1) / 2;
            if (v % n == r)
            {
                ans = true;
                break;
            }
        }
        if (ans)
            cout << "Yes" << '\n';
        else
            cout << "No" << '\n';
    }

    return 0;
}