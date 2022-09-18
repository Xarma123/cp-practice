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
    map<string, vector<pair<lol, lol>>> mp;

    while (n--)
    {
        string s;
        cin >> s;
        lol q;
        cin >> q;
        if (mp.count(s))
        {
            mp[s].push_back({mp[s].back().first + q, n});
        }
        else
            mp[s].push_back({q, n});
    }
    lol mx = LONG_LONG_MIN;
    for (auto i = mp.begin(); i != mp.end(); i++)
    {
        if ((*i).second.back().first > mx)
            mx = (*i).second.back().first;
    }
    set<string> g;
    for (auto i = mp.begin(); i != mp.end(); i++)
    {
        if ((*i).second.back().first == mx)
            g.insert((*i).first);
    }

    lol t = LONG_LONG_MIN;
    string ans; 
   
    for (auto i = g.begin(); i != g.end(); i++)
    {   
        for (lol j = 0; j < mp[(*i)].size(); j++)
        {
            if (mp[(*i)][j].first >= mx)
            {
                if (t < mp[(*i)][j].second)
                {
                    ans = (*i);
                    t = mp[(*i)][j].second;
                }
                break;
            }
        }
    }
    cout << ans;

    return 0;
}