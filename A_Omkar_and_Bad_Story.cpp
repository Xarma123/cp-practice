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
        bool f = true;
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
            if (a[i] < 0)
                f = false;
        }
        if (f)
        {
            cout << "YES\n";
            cout << 101 << '\n';
            for (lol i = 0; i < 101; i++)
            {
                cout << i << " ";
            }
        }
        else
            cout << "NO\n";
    }

    return 0;
}