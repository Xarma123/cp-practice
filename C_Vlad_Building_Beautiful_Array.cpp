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
        lol odmin = LONG_LONG_MAX;
        lol evmin = LONG_LONG_MAX;
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
            if (a[i] % 2)
                odmin = min(a[i], odmin);
            else
                evmin = min(evmin, a[i]);
        }
        if (evmin == LONG_LONG_MAX || odmin == LONG_LONG_MAX)
            cout << "YES\n";
        else if (evmin > odmin)
        {
            cout << "YES\n";
        }
        else
            cout << "NO\n";
    }
}