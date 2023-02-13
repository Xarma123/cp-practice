#include <bits/stdc++.h>
#define lol long long
using namespace std;
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
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        lol i = 0, j = n - 1;
        map<lol, lol> mp;
        vector<lol> mn, mx;
        while (i < j)
        {
            mp[a[i] + a[j]]++;
            mn.push_back(min(a[i], a[j]));
            mx.push_back(max(a[i], a[j]) + k);
            i++;
            j--;
        }
        sort(mn.begin(), mn.end());
        sort(mx.begin(), mx.end());
        lol ans = LONG_LONG_MAX;
        for (auto e : mp)
        {
            lol v = e.first;
            lol f = e.second;
            lol i = lower_bound(mn.begin(), mn.end(), v) - mn.begin();
            i = mn.size() - i;
            lol j = lower_bound(mx.begin(), mx.end(), v) - mx.begin();
            ans = min(ans, n / 2 - f + i + j);
        }
        cout << min(ans, n / 2) << '\n';
    }

    return 0;
}