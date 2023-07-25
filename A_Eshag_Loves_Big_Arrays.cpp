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
        lol i = 1;
        for (; i < n; i++)
        {
            if (a[i] != a[i - 1])
                break;
        }
        cout << n - i << '\n';
    }
}