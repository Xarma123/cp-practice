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
        lol n;
        cin >> n;
        lol a[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        sort(a, a + n);
        lol i;
        for (i = 0; i <= n; i++)
        {
            lol j = upper_bound(a, a + n, i) - a;
            if (n - j == i)
            {
                cout << i << '\n';
                break;
            }
        }
        if (i == n + 1)
            cout << -1 << '\n';
    }

    return 0;
}