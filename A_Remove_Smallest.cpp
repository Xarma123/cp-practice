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
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        sort(a, a + n);
        lol i;
        for (i = 1; i < n; i++)
        {
            if (a[i] - a[i - 1] > 1)
            {
                break;
            }
        }
        if (i == n)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}