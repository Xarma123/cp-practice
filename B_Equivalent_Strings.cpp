#include <bits/stdc++.h>
#define lol long long
using namespace std;
map<pair<string, string>, bool> mp;
bool solve(string a, string b)
{
    if (mp.count({a, b}))
        return mp[{a, b}];
    if (a == b)
        return mp[{a, b}] = true;
    if (a.size() % 2 != 0)
        return mp[{a, b}] = false;
    string a1 = a.substr(0, (a.size() / 2));
    string a2 = a.substr((a.size() / 2), (a.size() / 2));
    string b1 = b.substr(0, (a.size() / 2));
    string b2 = b.substr((a.size() / 2), (a.size() / 2));
    if (solve(a1, b1) && solve(a2, b2))
        return mp[{a, b}] = true;
    if (solve(a1, b2) && solve(a2, b1))
        return mp[{a, b}] = true;
    return mp[{a, b}] = false;
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string a, b;
    cin >> a >> b;
    if (solve(a, b))
        cout << "YES\n";
    else
        cout << "NO\n";

    return 0;
}