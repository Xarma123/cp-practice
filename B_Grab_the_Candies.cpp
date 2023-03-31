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
        lol ev = 0;
        lol od = 0;
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
            if (a[i] % 2 == 0)
                ev += a[i];
            else
                od += a[i];
        }
        if (ev > od)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}