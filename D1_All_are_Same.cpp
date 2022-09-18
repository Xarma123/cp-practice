#include <bits/stdc++.h>
#define lol long long
using namespace std;
lol gcd(lol a, lol b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}
lol findGCD(lol arr[], lol n)
{
    lol result = arr[0];
    for (lol i = 1; i < n; i++)
    {
        result = gcd(arr[i], result);

        if (result == 1)
        {
            return 1;
        }
    }
    return result;
}
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        lol n;
        cin >> n;
        lol a[n];
        lol mn = INT_MAX;
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
            mn = min(a[i], mn);
            /* code */
        }
        for (lol i = 0; i < n; i++)
        {
            a[i] = a[i] - mn;
            /* code */
        }
        lol q = findGCD(a, n);
        if (q == 0)
            cout << -1 << endl;
        else
            cout << q << endl;
    }

    return 0;
}