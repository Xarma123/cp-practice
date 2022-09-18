#include <bits/stdc++.h>
#define lol long long
using namespace std;
bool compareit(lol n, pair<lol, lol> &p)
{
    return p.second > n;
}
int main()
{

    lol n;
    cin >> n;
    vector<pair<lol, lol>> s;
    map<lol,lol> mp;
    for (lol i = 0; i < n; i++)
    {
        lol l;
        cin >> l;
        lol mx = LONG_LONG_MIN;
        lol mn = LONG_LONG_MAX;
        lol prv = LONG_LONG_MAX;
        bool f = true;
        for (lol j = 0; j < l; j++)
        {
            lol t;
            cin >> t;
            if (t > prv)
                f = false;
            prv = t;
            mx = max(mx, t);
            mn = min(mn, t);
        }
        if (f)
        {
            s.push_back(make_pair(mx, mn));
            if (mn == mx)
            {
                mp[mn]++;
            }
        }
    }
    lol sz = s.size();
    pair<lol, lol> a[sz];
    for (lol i = 0; i < sz; i++)
    {
        a[i] = s[i];
    }
    s.clear();
    sort(a, a + sz);

    lol w = 0;

    for (lol i = sz - 1; i >= 0; i--)
    {

        lol c = a[i].second;
        lol j = upper_bound(a, a + i, make_pair(c, LONG_LONG_MAX)) - a;
        w += j;
        if (a[i].second == a[i].first)
        {
            w += 1;
            if (mp.count(a[i].first))
            {
                mp[a[i].first]--;
                w += mp[a[i].first];
                if (mp[a[i].first] == 0)
                {
                    mp.erase(a[i].first);
                }
            }
        }
    }
    cout << n * n - w << endl;

    return 0;
}