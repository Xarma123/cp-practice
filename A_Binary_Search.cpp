#include <bits/stdc++.h>
#define lol long long
using namespace std;
bool b(lol a[], lol x, lol n)
{
    lol s = 0;
    lol e = n - 1;
    while (s <= e)
    {
        lol m = (s + e) / 2;
        if (a[m] == x)
            return true;
        if (a[m] > x)
        {
            e = m - 1;
        }
        if (a[m] < x)
        {
            s = m + 1;
        }
    } 
    return false;
}
int main()
{
    lol n, k;
    cin >> n >> k;
    lol a[n];
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    while (k--)
    {
        lol x;
        cin >> x;
        if (b(a, x, n))
        {
            cout << "YES" << endl;
        }
        else
            cout << "NO" << endl;
    }

    return 0;
}