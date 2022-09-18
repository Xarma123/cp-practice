#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        lol n;
        cin >> n;
        lol a[n];
        lol s = 0;
        lol mx = LONG_LONG_MIN;
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
            mx = max(mx, a[i]);
            s += a[i];
        }
        if (mx > ceill(s / 2.0))
            cout << "T" << endl;
        else if (s % 2 == 0)
            cout << "HL" << endl;
        else
            cout << "T" << endl;
    }

    return 0;
}