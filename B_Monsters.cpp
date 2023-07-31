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
        lol n, k;
        cin >> n >> k;
        lol a[n];
        pair<lol, lol> b[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];

            a[i] %= k;
            if (a[i] == 0)
                a[i] = k;
            b[i] = {a[i], -(i + 1)};
        }
        sort(b, b + n);
        for (lol i = n - 1; i >= 0; i--)
        {
            cout << -b[i].second << " ";
        }
        cout << '\n';
    }
}