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
    for (lol qqqw = 1; qqqw <= t; qqqw++)
    {
        cout << "Case #" << qqqw << ": ";
        lol n;
        cin >> n;
        lol a[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        map<lol, lol> mp;
        bool f = true;
        lol s = 1;
        for (lol i = 0; i < n; i++)
        {
            lol j = i + 1;
            while (j < n && a[j] == a[i])
                j++;
            if (mp.count(a[i]))
            {
                f = false;
                break;
            }
            mp[a[i]] = (s++);
            i = j - 1;
        }
        if (!f)
        {
            cout << "IMPOSSIBLE\n";
            continue;
        }
        vector<pair<lol, lol>> v;
        for (auto e : mp)
        {
            v.push_back({e.second, e.first});
        }
        sort(v.begin(), v.end());
        for (auto e : v)
            cout << e.second << " ";
        cout << '\n';
    }

    return 0;
}