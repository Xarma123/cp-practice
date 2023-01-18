#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n;
    cin >> n;
    map<lol, lol> mp;
    while (n--)
    {
        lol q;
        cin >> q;
        mp[q]++;
    }
    lol ans = 0;
    vector<lol> q;
    while (!mp.empty())
    {
        lol v = (*mp.rbegin()).first;
        if (mp[v] >= 2)
        {
            mp[v] -= 2;
            if (mp[v] == 0)
                mp.erase(v);
            q.push_back(v);
        }
        else
        {
            mp.erase(v);
            v--;
            mp[v]++;
            if (mp[v] >= 2)
            {
                mp[v] -= 2;
                if (mp[v] == 0)
                    mp.erase(v);
                q.push_back(v);
            }
            else
            {
                mp.erase(v);
            }
        }
    }

    for (lol i = 0; i < (long long)q.size() - 1; i += 2)
    {
        ans += q[i] * 1ll * q[i + 1];
    }

    cout << ans;

    return 0;
}