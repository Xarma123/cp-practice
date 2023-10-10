#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol t;
    cin >> t;
    while (t--)
    {
        lol n, p;
        cin >> n >> p;
        pair<lol, lol> a[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i].second;
        }
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i].first;
        }
        sort(a, a + n);
        lol ans = p * 1ll * n;
        lol ex = p;
        lol l = 0;
        for (lol i = 0; i < n; i++)
        {
            while (i > l)
            {
                ex += p;
                l++;
            }
            if (a[i].first <= p)
            {

                ex += a[i].first * 1ll * (min(l + a[i].second, n - 1) - l);
                l += a[i].second;
                l = min(l, n - 1);
            }
        }
        cout << min(ans, ex) << '\n';
    }
}