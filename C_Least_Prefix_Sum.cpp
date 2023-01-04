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
        lol n, m;
        cin >> n >> m;
        lol a[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        lol ans = 0;
        lol c = 0;
        map<lol, vector<lol>> mp;
        for (lol i = m - 1; i > 0; i--)
        {
            c += a[i];
            mp[-a[i]].push_back(i);
            if (c > 0)
            {
                ans++;
                lol j = (*mp.begin()).second.back();
                c -= a[j];
                a[j] = -a[j];
                c += a[j];
                (*mp.begin()).second.pop_back();
                if ((*mp.begin()).second.size() == 0)
                {
                    mp.erase((*mp.begin()).first);
                }
            }
        }
        c = 0;
        mp.clear();
        for (lol i = m; i < n; i++)
        {
            c += a[i];
            mp[a[i]].push_back(i);
            if (c < 0)
            {
                ans++;
                lol j = (*mp.begin()).second.back();
                c -= a[j];
                a[j] = -a[j];
                c += a[j];
                (*mp.begin()).second.pop_back();
                if ((*mp.begin()).second.size() == 0)
                {
                    mp.erase((*mp.begin()).first);
                }
            }
        }

        cout << ans << '\n';
    }

    return 0;
}