#include <bits/stdc++.h>
using namespace std;
#define lol long long
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
        map<lol, lol> x, y, px, nx;
        while (n--)
        {
            lol a, b;
            cin >> a >> b;
            x[a]++;
            y[b]++;
            px[a + b]++;
            nx[a - b]++;
        }
        lol ans = 0;
        for (auto e : x)
        {
            lol c = e.second;
            ans += (c)*1ll * (c - 1) / 2ll;
        }
        for (auto e : y)
        {
            lol c = e.second;
            ans += (c)*1ll * (c - 1) / 2ll;
        }
        for (auto e : px)
        {
            lol c = e.second;
            ans += (c)*1ll * (c - 1) / 2ll;
        }
        for (auto e : nx)
        {
            lol c = e.second;
            ans += (c)*1ll * (c - 1) / 2ll;
        }
        cout << 2ll * ans << '\n';
    }
}