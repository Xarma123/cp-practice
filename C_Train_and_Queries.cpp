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

        map<lol, pair<lol, lol>> mp;
        lol n, k;
        cin >> n >> k;
        lol a[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
            if (mp.count(a[i]))
            {
                mp[a[i]].first = min(mp[a[i]].first, i);
                mp[a[i]].second = max(mp[a[i]].second, i);
            }
            else
            {
                mp[a[i]] = {i, i};
            }
        }
        while (k--)
        {
            lol a, b;
            cin >> a >> b;
            if (!mp.count(a) || !mp.count(b))
            {
                cout << "NO" << endl;
            }
            else
            {
                if (mp[a].first <= mp[b].second)
                    cout << "YES" << endl;
                else
                    cout << "NO" << endl;
            }
        }
    }

    return 0;
}