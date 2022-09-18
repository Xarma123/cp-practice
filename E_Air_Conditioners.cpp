#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol q;
    cin >> q;
    while (q--)
    {
        lol n, k;
        cin >> n >> k;
        pair<lol, lol> a[k];
        for (lol i = 0; i < k; i++)
        {
            lol t;
            cin >> t;
            a[i] = make_pair(t, 0);
        }
        for (lol i = 0; i < k; i++)
        {
            lol t;
            cin >> t;
            a[i] = make_pair(a[i].first - 1, t);
        }
        lol l[n], r[n];
        for (lol i = 0; i < n; i++)
        {
            l[i] = INT_MAX;
            r[i] = INT_MAX;
        }

        for (lol i = 0; i < k; i++)
        {
            l[a[i].first] = a[i].second;
            r[a[i].first] = a[i].second;
        }
        for (lol i = 1; i < n; i++)
        {
            if (i != 0)
                l[i] = min(l[i - 1] + 1, l[i]);
        }
        for (lol i = n - 2; i >= 0; i--)
        {
            r[i] = min(r[i], r[i + 1] + 1);
        }
        for (lol i = 0; i < n; i++)
        {
            cout << min(l[i], r[i]) << " ";
        }
        cout << endl;
    }

    return 0;
}