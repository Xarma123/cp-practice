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
        lol n, q;
        cin >> n >> q;
        lol a[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        lol c[n + 1];
        c[0] = 0;
        for (lol i = 1; i <= n; i++)
        {
            c[i] = c[i - 1] + a[i - 1];
        }
        while (q--)
        {
            lol l, r, k;
            cin >> l >> r >> k;
            lol sum = c[l - 1] + c[n] - c[r] + k * 1ll*(r - l + 1);
            if (sum % 2)
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }

    return 0;
}