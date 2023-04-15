#include <bits/stdc++.h>
#define lol long long
using namespace std;
string s;
map<vector<lol>, bool> mp;
bool solve(lol i, lol a, lol b, lol c, lol d)
{
    if (i == s.size())
    {
        if (a || b || c || d)
            return false;
        return true;
    }
    if (mp.count({i, a, b, c, d}))
        return mp[{i, a, b, c, d}];
    if (i + 1 < s.size() && s[i] == 'A' && s[i + 1] == 'B' && c > 0)
    {
        if (solve(i + 2, a, b, c - 1, d))
            return mp[{i, a, b, c, d}] = true;
    }
    if (i + 1 < s.size() && s[i] == 'B' && s[i + 1] == 'A' && d > 0)
    {
        if (solve(i + 2, a, b, c, d - 1))
            return mp[{i, a, b, c, d}] = true;
    }
    if (s[i] == 'A' && a > 0)
    {
        if (solve(i + 1, a - 1, b, c, d))
            return mp[{i, a, b, c, d}] = true;
    }
    if (s[i] == 'B' && b > 0)
    {
        if (solve(i + 1, a, b - 1, c, d))
            return mp[{i, a, b, c, d}] = true;
    }

    return mp[{i, a, b, c, d}] = false;
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
        mp.clear();
        lol a, b, c, d;
        cin >> a >> b >> c >> d;
        cin >> s;
        if (solve(0, a, b, c, d))
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}