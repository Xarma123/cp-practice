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
    if (n == 0)
        cout << 1;
    else
    {
        lol m = 1e9 + 7;
        lol p = 1;
        lol a = 2;
        lol _n = 2ll * n - 1;
        n--;
        while (n)
        {
            if (n % 2)
                p = (p * 1ll * a) % m;
            n /= 2;
            a = (a * a) % m;
        }
        lol p2 = 1;
        a = 2;
        n = _n;
        while (n)
        {
            if (n % 2)
                p2 = (p2 * 1ll * a) % m;
            n /= 2;
            a = (a * a) % m;
        }
        cout << (p + p2) % m;
    }

    return 0;
}