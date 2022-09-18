#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol n;
    cin >> n;
    lol a[n];
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n);
    lol k;
    cin >> k;
    while (k--)
    {
        lol l, r;
        cin >> l >> r;
        lol s = -1;
        lol e = n;

        while (s != e - 1)
        {
            lol m = (s + e) / 2;
            if (a[m] <= r)
            {
                s = m;
            }
            else
            {
                e = m;
            }
        }
        lol f = s;
        if (s == -1)
        {
            cout << 0 << " ";
        }
        else
        {
            s = -1;
            e = n;

            while (s != e - 1)
            {
                lol m = (s + e) / 2;
                if (a[m] < l)
                {
                    s = m;
                }
                else
                {
                    e = m;
                }
            }
            if (e == n)
            {
                cout << 0 << " ";
            }
            else
            {
                cout << f - e + 1 << " ";
            }
        }
    }

    return 0;
}