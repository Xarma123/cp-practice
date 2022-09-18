#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol T;
    cin >> T;
    while (T--)
    {
        lol n, m;
        cin >> n >> m;
        lol a[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        lol i;
        for (i = n - 1; i >= 0; i--)
        {
            if (a[i] != i + 1)
                break;
        }
        i++;

        long double sum = 1;
        bool f = true;
        while (m--)
        {
            long double r, p;
            cin >> r >> p;
            if (r >= i)
            {
                f = false;
                sum *= (1 - p);
            }
        }
        if (i == 0)
            cout << 1 << endl;
        else if (f)
        {
            cout << 0 << endl;
        }
        else
        {
            cout << setprecision(6) << (long double)1 - sum << endl;
        }
    }
    return 0;
}