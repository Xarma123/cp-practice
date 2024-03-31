#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n;
    cin >> n;
    lol c;
    cin >> c;
    vector<pair<lol, lol>> o(c);
    for (lol i = 0; i < c; i++)
    {
        cin >> o[i].first >> o[i].second;
    }
    cin >> c;
    vector<pair<lol, lol>> w(c);
    for (lol i = 0; i < c; i++)
    {
        cin >> w[i].first >> w[i].second;
    } 
    
    lol d[2ll * n + 1];
    for (lol i = 0; i < 2ll * n + 1; i++)
    {
        d[i] = INT_MAX;
    }
    d[0] = 0;
    for (lol i = 0; i < 3ll * n; i++)
    {
        d[1] = min(d[1], d[0]);
        d[1 + n] = min(d[1 + n], d[0]);
        for (auto e : o)
        {
            // e.first -> e.second
            lol v = e.first + n + 1;
            lol u = e.second + 1;
            d[u] = min(d[u], d[v] + 1);
        }
        for (auto e : w)
        {
            // e.first -> e.second
            lol v = e.first + 1;
            lol u = e.second + n + 1;
            d[u] = min(d[u], d[v] + 1);
        }
    }
    vector<lol> ans;
    for (lol i = 1; i <= n; i++)
    {
        lol x = min(d[i], d[i + n]);
        if (x == INT_MAX)
            x = -1;
        ans.push_back(x);
    }
    for (auto e : ans)
        cout << e << endl;

    return 0;
}
