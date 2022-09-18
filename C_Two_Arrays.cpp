#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol T;
    cin >> T;
    while (T--)
    {
        lol n;
        cin >> n;
        lol a[n], b[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (lol i = 0; i < n; i++)
        {
            cin >> b[i];
        }
        sort(a, a + n);
        sort(b, b + n);
        lol i;
        for (i = 0; i < n; i++)
        {
            if (!(a[i] == b[i] || a[i] + 1 == b[i]))
            {
                break;
            }
        }
        if (i == n)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}