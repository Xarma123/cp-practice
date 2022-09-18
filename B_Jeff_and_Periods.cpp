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
    map<lol, vector<lol>> mp;
    for (lol i = 0; i < n; i++)
    {
        lol q;
        cin >> q;
        mp[q].push_back(i);
    }
    vector<pair<lol, lol>> ans;
    for (auto e : mp)
    {
        if (e.second.size() == 1)
        {
            ans.push_back({e.first, 0});
        }
        else
        {
            lol d = e.second[1] - e.second[0];
            bool f = true;
            for (lol i = 0; i < e.second.size() - 1; i++)
            {
                if (e.second[i + 1] - e.second[i] != d)
                    f = false;
            }
            if (f)
                ans.push_back({e.first, d});
        }
    }
    cout << ans.size() << endl;
    for (auto e : ans)
    {
        cout << e.first << " " << e.second << endl;
    }

    return 0;
}