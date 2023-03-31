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
        lol mn = LONG_LONG_MAX;
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
            mn = min(mn, a[i]);
        }
        lol c = 0;
        for (lol i = 0; i < n; i++)
        {
            if (a[i] == mn)
                c++;
        }
        cout << n - c << '\n';
    }

    return 0;
}