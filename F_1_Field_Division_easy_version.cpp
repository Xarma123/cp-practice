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
        lol n, m, k;
        cin >> n >> m >> k;
        pair<lol, pair<lol, lol>> a[k];
        for (lol i = 0; i < k; i++)
        {
            cin >> a[i].first >> a[i].second.first;
            a[i].first--;
            a[i].second.first--;
            a[i].second.first *= -1ll;
            a[i].second.second = i;
        }
        sort(a, a + k);
        for (lol i = 0; i < k; i++)
        {
            a[i].second.first *= -1ll;
        }

        lol mn[k];
        for (lol i = k - 1; i >= 0; i--)
        {
            if (i == k - 1)
            {
                mn[i] = i;
            }
            else
            {
                if (a[i].second.first <= a[mn[i + 1]].second.first)
                {
                    mn[i] = i;
                }
                else
                    mn[i] = mn[i + 1];
            }
        }
        lol l = 0;
        lol ans = 0;
        for (lol i = 0; i < k; i++)
        {
            if (a[mn[i]].second.first == 0)
            {
                l = a[mn[i]].first + 1;
                continue;
            }
            lol v = a[mn[i]].second.first;
            ans += (a[i].first - l + 1) * 1ll * v;
            l = a[i].first + 1;
        }

        ans += m * 1ll * (n - l);
        cout << ans << endl;
        lol f[k];
        memset(f, 0, sizeof(f));
        lol i = 0;
        while (i < k)
        {
            lol j = mn[i] + 1;
            if (j < k)
            {
                if (a[mn[j]].second.first != a[mn[i]].second.first)
                {
                    f[a[mn[i]].second.second] = 1;
                }
            }
            else
            {
                f[a[mn[i]].second.second] = 1;
            }
            i = j;
        }
        for (lol i = 0; i < k; i++)
        {
            cout << f[i] << " ";
        }

        cout << endl;
    }

    return 0;
}
