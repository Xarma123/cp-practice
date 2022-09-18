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
        lol x;
        cin >> x;
        lol a[n];
        lol s = -1;
        lol e = -1;
        lol sum = 0;
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
            sum += a[i];
            if (s == -1 && a[i] % x != 0)
                s = i;
            if (a[i] % x != 0)
                e = i;
        }
        if (s == -1)
            cout << -1 << endl;
        else
        {
            if (sum % x != 0)
                cout << n << endl;
            else
                cout << n - min(s + 1, n - e) << endl;
        }
    }

    return 0;
}