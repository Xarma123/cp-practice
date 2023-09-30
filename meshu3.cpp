#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n;
    cin >> n;
    lol p;
    cin >> p;
    lol g[n];
    for (lol i = 0; i < n; i++)
    {
        cin >> g[i];
    }
    lol ans = 0;
    lol pwer[n];
    for (lol i = 0; i < n; i++)
    {
        cin >> pwer[i];
    }
    lol l = n / 2;
    vector<pair<lol, lol>> a;
    for (lol i = 0; i < (1ll << l); i++)
    {
        lol cp = 0, cg = 0;
        for (lol j = 0; j < l; j++)
        {
            if ((i & (1ll << j)))
            {
                cp += pwer[j];
                cg += g[j];
            }
        }
        if (cp <= p)
        {
            ans = max(ans, cg);
            a.push_back({cp, cg});
        }
    }
    l = n - l;
    vector<pair<lol, lol>> b;
    for (lol i = 0; i < (1ll << l); i++)
    {
        lol cp = 0, cg = 0;
        for (lol j = 0; j < l; j++)
        {
            if ((i & (1ll << j)))
            {
                cp += pwer[j + n / 2];
                cg += g[j + n / 2];
            }
        }
        if (cp <= p)
        {
            ans = max(ans, cg);
            b.push_back({cp, cg});
        }
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    for (lol i = 1; i < a.size(); i++)
    {
        a[i].second = max(a[i].second, a[i - 1].second);
    }
    for (lol i = 1; i < b.size(); i++)
    {
        b[i].second = max(b[i].second, b[i - 1].second);
    }

    for (lol i = 0; i < b.size(); i++)
    {
        lol pww = b[i].first;
        lol gg = b[i].second;

        pair<lol, lol> d = {p - pww, LONG_LONG_MAX};
        lol j = upper_bound(a.begin(), a.end(), d) - a.begin();
        j--;
        if (j >= 0)
        {
            ans = max(ans, a[j].second + gg);
        }
    }
    cout << ans;
}