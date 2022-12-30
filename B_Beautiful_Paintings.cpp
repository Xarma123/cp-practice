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
    for (lol i = 0; i < n; i++)
    {
        lol q;
        cin >> q;
        mp[q]++;
    }
    vector<lol> q;
    while (1)
    {
        bool f = true;
        for (auto e : mp)
        {
            if (e.second > 0)
            {
                q.push_back(e.first);
                mp[e.first]--;
                f = false;
            }
        }
        if (f)
            break;
    }
    lol ans = 0;

    for (lol i = 0; i + 1 < q.size(); i++)
    {
        if (q[i] < q[i + 1])
            ans++;
    }
    cout << ans;

    return 0;
}