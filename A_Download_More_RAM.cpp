#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        lol n, k;
        cin >> n >> k;
        pair<lol, lol> a[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i].first;
        }
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i].second;
        }
        sort(a, a + n);
        for (lol i = 0; i < n; i++)
        {
            if (a[i].first > k)
            {
                break;
            }
            else
            {
                k += a[i].second;
            }
        }
        cout << k << endl;
    }

    return 0;
}