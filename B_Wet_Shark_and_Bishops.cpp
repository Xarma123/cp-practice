#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    map<lol, lol> d;
    map<lol, lol> s;
    lol n;
    cin >> n;
    while (n--)
    {
        lol a, b;
        cin >> a >> b;
        s[a + b]++;
        d[a - b]++;
    }
    lol ans = 0;
    for (auto e : s)
    {
        ans += e.second * 1ll * (e.second - 1) / 2;
    }
    for (auto e : d)
    {
        ans += e.second * 1ll * (e.second - 1) / 2;
    }
    cout << ans;

    return 0;
}