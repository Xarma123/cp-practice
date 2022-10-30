#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, q;
    cin >> n >> q;
    lol a[n];
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (lol i = 1; i < n; i++)
    {
        a[i] += a[i - 1];
    }
    lol tc = 0;
    while (q--)
    {
        lol c = 0;
        cin >> c;
        tc += c;
        lol i = upper_bound(a, a + n, tc) - a;
        if (i == n)
        {
            tc = 0;
            cout << n << endl;
        }
        else
        {
            cout << n - i << endl;
        }
    }

    return 0;
}