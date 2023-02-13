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
        lol a, b, n, m;
        cin >> a >> b >> n >> m;
        if (n <= m)
        {
            cout << min(a, b) * 1ll * n << '\n';
        }
        else
        {
            if (a <= b)
            {
                cout << ((n / (m + 1)) * 1ll * a * m + (n % (m + 1)) * 1ll * a) << '\n';
            }
            else if (m * 1ll * a < (m + 1) * 1ll * b)
            {
                cout << ((n / (m + 1)) * 1ll * a * m + (n % (m + 1)) * 1ll * b) << '\n';
            }
            else
                cout << b * 1ll * n << '\n';
        }
    }

    return 0;
}