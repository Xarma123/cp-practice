#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol n, k;
    cin >> n >> k;
    lol a[n];
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    lol x;
    while (k--)
    {
        cin >> x;
        lol s = -1;
        lol e = n;

        while (s != e - 1)
        {
            lol m = (s + e) / 2;
            if (a[m] < x)
            {
                s = m;
            }
            else
            {
                e = m;
            }
        }
        cout << e + 1 << endl;
    }

    return 0;
}