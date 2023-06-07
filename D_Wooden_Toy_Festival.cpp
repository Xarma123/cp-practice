#include <bits/stdc++.h>
using namespace std;
#define lol long long
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
        sort(a, a + n);
        lol s = -1, e = 1e12;
        while (s != e - 1)
        {
            lol m = (s + e) / 2ll;
            if (m == -1)
                s = m;
            else
            {
                lol nx = a[0] + m + m;
                lol c = 1;
                for (lol i = 0; i < n; i++)
                {
                    if (a[i] > nx)
                    {
                        nx = a[i] + m + m;
                        c++;
                    }
                }
                if (c <= 3)
                {
                    e = m;
                }
                else
                    s = m;
            }
        }
        cout << e << '\n';
    }
}