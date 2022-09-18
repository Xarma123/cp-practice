#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol n, k;
    cin >> n >> k;
    lol a[n];
    pair<lol, lol> b[n];
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (lol i = 0; i < n; i++)
    {
        lol t;
        cin >> t;
        t = a[i] - t;
        b[i] = make_pair(t, i);
    }
    sort(b, b + n);
    lol ans = 0;
    for (lol i = 0; i < n; i++)
    {
        if (b[i].first <= 0 || k)
        {

            if (k > 0)
                k--;
            ans += a[b[i].second];
        }
        else
        {

            ans += a[b[i].second] - b[i].first;
        }
    }
    cout << ans;

    return 0;
}