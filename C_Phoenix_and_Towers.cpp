#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        lol n, x, m;
        cin >> n >> m >> x;
        pair<lol, lol> a[n];

        for (lol i = 0; i < n; i++)
        {
            cin >> a[i].first;
            a[i].second = i;
        }
        sort(a, a + n);
        if (n < m)
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES" << endl;
            lol c = 1;
            for (lol i = 0; i < n; i++)
            {
                a[i].first = c;
                c++;
                if (c > m)
                    c = 1;
            }
            lol ans[n];
            for (lol i = 0; i < n; i++)
            {
                ans[a[i].second] = a[i].first;
            }
            for (lol i = 0; i < n; i++)
            {
                cout << ans[i] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}