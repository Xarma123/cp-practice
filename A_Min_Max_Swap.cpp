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
        pair<lol, lol> a[n];
        lol mx = LONG_LONG_MIN;
        for (lol i = 0; i < n; i++)
        {
            lol T;
            cin >> T;
            mx = max(T, mx);
            a[i] = make_pair(T, 0);
        }

        for (lol i = 0; i < n; i++)
        {
            lol T;
            cin >> T;
            mx = max(T, mx);

            a[i].second = T;
        }
       
     
        for (lol i = 0; i < n; i++)
        {
            if (a[i].second == mx)
            {
                swap(a[i].first, a[i].second);
            }
             if (a[i].second >= a[i].first)
            {
                swap(a[i].second, a[i].first);
            }
        }
        lol mx2 = LONG_LONG_MIN;
        for (lol i = 0; i < n; i++)
        {
            if (a[i].second > mx2)
            {
                mx2 = a[i].second;
            }
        }
        cout << mx * mx2 << endl;
    }

    return 0;
}