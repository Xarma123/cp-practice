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
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (lol i = 0; i < n; i++)
        {
            if (i == 0)
                cout << 0 << " ";
            else
            {
                cout << ((a[i] & a[i - 1]) ^ (a[i - 1]));
                if (i != n - 1)
                    cout << " ";
                a[i] = ((a[i] & a[i - 1]) ^ (a[i - 1])) ^ (a[i]);
            }
        }
        cout << endl;
    }

    return 0;
}