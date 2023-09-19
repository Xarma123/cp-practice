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
        lol n, k;
        cin >> n >> k;
        lol a[n];
        lol ans[k + 1];
        memset(ans, 0, sizeof(ans));
        map<lol, vector<lol>> mp;
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
            ans[a[i]] = 1;
            mp[a[i]].push_back(i);
        }
        pair<lol, lol> rw[k + 1];
        lol l = LONG_LONG_MAX;
        lol r = LONG_LONG_MIN;
        for (lol i = k; i >= 1; i--)
        {
            for (auto e : mp[i])
            {
                l = min(l, e);
                r = max(r, e);
            }
            if (ans[i])
                ans[i] = 2ll * (r - l + 1);
        }
        for (lol i = 1; i <= k; i++)
        {
            cout << ans[i] << " ";
        }
        cout << '\n';
    }
}