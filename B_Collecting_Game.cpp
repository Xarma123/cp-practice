#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol t;
    cin >> t;
    while (t--)
    {
        lol n;
        cin >> n;
        lol a[n];
        pair<lol, lol> b[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
            b[i] = {a[i], i};
        }
        sort(b, b + n);
        sort(a, a + n);
        lol p[n];
        for (lol i = 0; i < n; i++)
        {
            p[i] = b[i].first;
            if (i)
                p[i] += p[i - 1];
        }
        lol ans[n];
        for (lol i = n - 1; i >= 0; i--)
        {
            lol j = upper_bound(a, a + n, p[i]) - a - 1;

            if (j == n - 1)
            {
                ans[b[i].second] = j;
            }
            else if (j > i)
            {
                ans[b[i].second] = ans[b[j].second];
            }
            else
                ans[b[i].second] = i;
        }
        for (lol i = 0; i < n; i++)
        {
            cout << ans[i] << " ";
        }
        cout << '\n';
    }

    return 0;
}
