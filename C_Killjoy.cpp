#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        lol n, x;
        cin >> n >> x;
        lol a[n];
        lol s = 0;
        bool f = true, z = true;
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
            s += x - a[i];
            if (a[i] != x)
                f = false;
            if (a[i] == x)
                z = false;
        }
        if (s == 0)
        {
            if (f)
                cout << 0 << endl;
            else
                cout << 1 << endl;
        }
        else
        {
            if (z)
            {
                cout << 2 << endl;
            }
            else
                cout << 1 << endl;
        }
    }

    return 0;
}