#include <bits/stdc++.h>
#define lol long long
using namespace std;
lol lcm(lol a, lol b)
{
    return (a * 1ll * b) / __gcd(a, b);
}
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
        lol a[n], b[n + 1];
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
            if (i == 0)
                b[i] = a[i];
            else
                b[i] = lcm(a[i], a[i - 1]);
        }
        b[n] = a[n - 1];
        bool ans = true;
        for (lol i = 0; i < n && ans; i++)
        {
            if (__gcd(b[i], b[i + 1]) != a[i])
                ans = false;
        }
        if (ans)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}