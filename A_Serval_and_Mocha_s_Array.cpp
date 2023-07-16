#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
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
        lol g = LONG_LONG_MAX;
        for (lol i = 0; i < n; i++)
        {
            for (lol j = i + 1; j < n; j++)
            {
                g = min(g, __gcd(a[i], a[j]));
            }
        }
        if (g <= 2)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
}