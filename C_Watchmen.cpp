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
    map<lol, lol> x;
    map<lol, lol> y;
    map<pair<lol, lol>, lol> z;
    while (n--)
    {
        lol x1, y1;
        cin >> x1 >> y1;
        x[x1]++;
        y[y1]++;
        z[{x1, y1}]++;
    }
    lol ans = 0;
    for (auto e : x)
    {
        ans += e.second * 1ll * (e.second - 1) / 2;
    }
    for (auto e : y)
    {
        ans += e.second * 1ll * (e.second - 1) / 2;
    }
    for (auto e : z)
    {
        ans -= e.second * 1ll * (e.second - 1) / 2;
    }
    cout << ans;

    return 0;
}