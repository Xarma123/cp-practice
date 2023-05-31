    #include <bits/stdc++.h>
    using namespace std;
    #define lol long long
    map<lol, vector<pair<lol, lol>>> mp;

    lol dfs(lol c, lol p, lol baap)
    {
        lol ans = 0;
        for (auto e : mp[c])
        {
            if (e.first != p)
            {
                ans = max(ans, dfs(e.first, c, e.second) + (e.second < baap));
            }
        }
        return ans;
    }
    int main()
    {
        lol t;
        cin >> t;
        while (t--)
        {
            lol n;
            cin >> n;
            pair<lol, lol> edg[n - 1];
            mp.clear();
        
            for (lol i = 0; i < n - 1; i++)
            {
                cin >> edg[i].first >> edg[i].second;
                mp[edg[i].first].push_back({edg[i].second, i});
                mp[edg[i].second].push_back({edg[i].first, i});
            }
            cout << dfs(1, -1, -1) + 1 << '\n';
        }
    }