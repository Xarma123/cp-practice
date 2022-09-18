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
        lol l = LONG_LONG_MIN;
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
            l = max(l, a[i]);
        }
        lol d[n - 1];
        for (lol i = 0; i < n - 1; i++)
        {
            d[i] = a[i + 1] - a[i];
        }
        bool f = true;
        bool ans = true;
        lol m = 0;
        for (lol i = 0; i < n - 2; i++)
        {
            if (d[i] != d[i + 1])
            {
                if (f)
                {
                    f = false;
                    m = abs(d[i] - d[i + 1]);
                }
                if (m != (abs(d[i] - d[i + 1])))
                {
                    ans = false;
                    break;
                }
            }
        }
        if (!f & (!ans || m <= l))
            cout << -1 << endl;
        else
        {
            if (m != 0)
            {
                cout << m << " ";
                if (d[0] >= 0)
                    cout << d[0] << endl;
                else
                {
                    cout << m + d[0] << endl;
                }
            }
            else
                cout << m << endl;
        }
    }

    return 0;
}