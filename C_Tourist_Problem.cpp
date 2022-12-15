#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n;
    cin >> n;
    lol a[n];
    lol c[n];
    lol s = 0;
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n);
    for (lol i = 0; i < n; i++)
    {
        c[i] = 0;
        if (i)
        {
            c[i] = c[i - 1];
            c[i] += a[i - 1];
        }

        s += a[i];
    }

    lol num = 0;
    for (lol i = 0; i < n; i++)
    {
        num += (i + 1) * 1ll * a[i] - c[i] + s - c[i] - a[i] - (n - 1 - i) * 1ll * a[i];
    }
    lol g = __gcd(num, (n));
    num /= g;
    n /= g;
    cout << num << " " << n;

    return 0;
}