#include <bits/stdc++.h>
#define lol long long
using namespace std;
bool check(lol a[], lol n)
{
    multiset<lol> mp;
    for (lol i = 0; i < n; i++)
    {
        mp.insert(a[i]);
    }
    bool f = true;
    auto j = mp.begin();

    for (lol i = 1; i <= n; i++)
    {
        if ((*j) != i)
        {
            return false;
        }
        j++;
    }
    return true;
}
int main()
{
    lol T;
    cin >> T;
    while (T--)
    {
        lol n;
        cin >> n;
        lol a[n];
        lol mx = LONG_LONG_MIN;
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
            mx = max(mx, a[i]);
        }

        vector<pair<lol, lol>> ans;
        if (check(a, mx) && check(a + mx, (n - mx)))
        {
            ans.push_back(make_pair(mx, (n - mx)));
        }
        if (mx != (n - mx))
        {
            if (check(a + (n - mx), mx) && check(a, (n - mx)))
            {
                ans.push_back(make_pair((n - mx), mx));
            }
        }
        cout << ans.size() << endl;
        for (lol i = 0; i < ans.size(); i++)
        {
            cout << ans[i].first << " " << ans[i].second << endl;
        }
    }
    return 0;
}