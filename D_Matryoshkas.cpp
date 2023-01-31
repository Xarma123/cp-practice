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
        lol n;
        cin >> n;
        map<lol, lol> mp;
        for (lol i = 0; i < n; i++)
        {
            lol q;
            cin >> q;
            mp[q]++;
        }
        lol ans = 0;
        while (!mp.empty())
        {
            lol v = (*mp.begin()).first;
            while (mp.count(v))
            {
                mp[v]--;
                if (mp[v] == 0)
                    mp.erase(v);
                v++;
            }
            ans++;
        }
        cout << ans << '\n';
    }

    return 0;
}