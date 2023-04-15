#include <bits/stdc++.h>
#define lol long long
using namespace std;
lol n, x;
map<lol, lol> mp;
lol solve(lol a)
{
    if (mp.count(a))
        return mp[a];
    string s = to_string(a);
    if (s.size() == n)
        return mp[a] = 0;
    if (s.size() > n)
        return mp[a] = LONG_LONG_MAX;
    set<char> x;
    for (auto e : s)
        x.insert(e);
    if ((*x.rbegin()) == '1')
        return mp[a] = LONG_LONG_MAX;
    lol ans = LONG_LONG_MAX;
    for (auto e : x)
    {
        if (e == '1' || e == '0')
            continue;
        lol q = e - '0';
        ans = min(ans, solve(a * 1ll * q));
    }

    if (ans != LONG_LONG_MAX)
        return mp[a] = ans + 1;
    return mp[a] = ans;
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> x;

    lol v = solve(x);
    if (v == LONG_LONG_MAX)
        v = -1;
    cout << v;

    return 0;
}