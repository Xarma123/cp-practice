#include <bits/stdc++.h>
#define lol long long
using namespace std;
lol ans = 0;
string s;
pair<lol, lol> cal(map<lol, vector<lol>> &mp, lol c)
{
    lol w = 0, b = 0;
    if (s[c - 1] == 'W')
        w++;
    else
        b++;
    for (lol i = 0; i < mp[c].size(); i++)
    {
        pair<lol, lol> x = cal(mp, mp[c][i]);
        w += x.first;
        b += x.second;
    }
    if (w == b)
        ans++;
    return {w, b};
}
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
        map<lol, vector<lol>> mp;
        for (lol i = 2; i <= n; i++)
        {
            lol p;
            cin >> p;
            mp[p].push_back(i);
        }

        cin >> s;
        cal(mp, 1);
        cout << ans << endl;
        ans = 0;
    }

    return 0;
}