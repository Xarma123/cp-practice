#include <bits/stdc++.h>
using namespace std;
#define lol long long
lol cal(lol a, lol b, lol c)
{
    return ((a - b) * 1ll * (a - b) + (a - c) * 1ll * (a - c) + (b - c) * 1ll * (b - c));
}
lol solve(vector<lol> a, vector<lol> b, vector<lol> c)
{
    lol ans = LONG_LONG_MAX;
    for (lol i = 0; i < a.size(); i++)
    {
        lol j = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
        if (j < b.size())
        {
            lol k = lower_bound(c.begin(), c.end(), b[j]) - c.begin();
            if (k < c.size())
            {
                ans = min(ans, cal(a[i], b[j], c[k]));
                lol d = c[k] - a[i];
                lol v = a[i] + d / 2;
                j = lower_bound(b.begin(), b.end(), v) - b.begin();
                if (j < b.size())
                    ans = min(ans, cal(a[i], b[j], c[k]));
                if (j - 1 >= 0)
                {
                    ans = min(ans, cal(a[i], b[j - 1], c[k]));
                }
                if (j + 1 < b.size())
                {
                    ans = min(ans, cal(a[i], b[j + 1], c[k]));
                }
            }
        }
    }
    return ans;
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol t;
    cin >> t;
    while (t--)
    {
        lol nr, ng, nb;
        cin >> nr >> ng >> nb;
        vector<lol> a(nr), b(ng), c(nb);
        for (lol i = 0; i < nr; i++)
        {
            cin >> a[i];
        }
        for (lol i = 0; i < ng; i++)
        {
            cin >> b[i];
        }
        for (lol i = 0; i < nb; i++)
        {
            cin >> c[i];
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        sort(c.begin(), c.end());
        lol ans = LONG_LONG_MAX;
        lol v = solve(a, b, c);
        ans = min(ans, v);
        v = solve(a, c, b);
        ans = min(ans, v);
        v = solve(b, a, c);
        ans = min(ans, v);
        v = solve(b, c, a);
        ans = min(ans, v);
        v = solve(c, b, a);
        ans = min(ans, v);
        v = solve(c, a, b);
        ans = min(ans, v);
        cout << ans << '\n';
    }
}