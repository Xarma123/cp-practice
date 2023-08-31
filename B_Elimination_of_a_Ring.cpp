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
        lol a[n];
        lol f[n + 1];
        memset(f, 0, sizeof(f));
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
            f[a[i]]++;
        }
        lol mn = LONG_LONG_MAX;
        lol q = 0;
        for (lol i = 0; i <= n; i++)
        {
            if (f[i])
            {
                q++;
                mn = min(mn, f[i]);
            }
        }
        if (mn == 1)
            cout << n << '\n';
        else if (q > 2)
            cout << n << '\n';
        else
            cout << n / 2+1 << '\n';
    }
}