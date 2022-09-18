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
        lol l, r;
        pair<lol, pair<lol, lol>> a[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> l >> r;
            lol sz = r - l;
            a[i] = make_pair(sz, make_pair(l, r));
        }
        sort(a, a + n);
        for (lol i = 1; i <= n; i++)
        {
            for (lol j = 0; j < n; j++)
            {
                if (a[j].second.first <= i && a[j].second.second >= i)
                {
                    cout << a[j].second.first << " " << a[j].second.second << " " << i << endl;

                    break;
                }
            }
        }
    }

    return 0;
}