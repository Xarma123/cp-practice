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
        lol x[n], y[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> x[i] >> y[i];
        }
        sort(x, x + n);
        sort(y, y + n);
        if (n % 2 != 0)
        {
            cout << 1 << endl;
        }
        else
        {
            cout << (x[(n / 2)] - x[(n / 2) - 1] + 1) * (y[(n / 2)] - y[(n / 2) - 1] + 1) << endl;
        }
    }

    return 0;
}