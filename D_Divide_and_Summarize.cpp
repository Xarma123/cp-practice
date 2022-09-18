#include <bits/stdc++.h>
#define lol long long
using namespace std;
set<lol> mp;
void quick(lol a[], lol n)
{
    if (n == 0)
        return;
    if (n == 1)
    {
        mp.insert(a[0]);
        return;
    }
    lol mn = LONG_LONG_MAX;
    lol mx = LONG_LONG_MIN;

    for (lol i = 0; i < n; i++)
    {
        mn = min(a[i], mn);
        mx = max(a[i], mx);
    }
    lol p = (mn + mx) / 2;
    lol j = -1;
    for (lol i = 0; i < n; i++)
    {
        if (a[i] <= p)
        {
            j++;
            swap(a[i], a[j]);
        }
    }
    lol s = 0, s2 = 0;
    for (lol i = 0; i < n; i++)
    {
        if (i <= j)
            s += a[i];
        else
            s2 += a[i];
    }
    mp.insert(s);
    mp.insert(s2);
    if ((j + 1 == 0) || (n - (j + 1)) == 0)
        return;
    quick(a, j + 1);
    quick(a + j + 1, n - (j + 1));
}
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        lol n, q;
        cin >> n >> q;
        lol a[n];
        lol s = 0;
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
            s += a[i];
        }
        mp.insert(s);
        quick(a, n);
        while (q--)
        {
            lol Q;
            cin >> Q;
            if (mp.count(Q))
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
        }

        mp.clear();
    }

    return 0;
}