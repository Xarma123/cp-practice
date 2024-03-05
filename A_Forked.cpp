#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol t;
    cin >> t;
    while (t--)
    {
        lol a, b;
        cin >> a >> b;

        lol x, y;
        cin >> x >> y;
        lol x1, y1;
        cin >> x1 >> y1;
        set<pair<lol, lol>> c;
        lol ans = 0;
        c.insert({x + a, y + b});
        c.insert({x - a, y + b});
        c.insert({x + a, y - b});
        c.insert({x - a, y - b});
        c.insert({x - b, y - a});
        c.insert({x + b, y - a});
        c.insert({x - b, y + a});
        c.insert({x + b, y + a});

        if (c.count({x1 + a, y1 + b}))
            ans++, c.erase({x1 + a, y1 + b});
        if (c.count({x1 + a, y1 - b}))
            ans++, c.erase({x1 + a, y1 - b});
        if (c.count({x1 - a, y1 + b}))
            ans++, c.erase({x1 - a, y1 + b});
        if (c.count({x1 - a, y1 - b}))
            ans++, c.erase({x1 - a, y1 - b});
        swap(a, b);

        if (c.count({x1 + a, y1 + b}))
            ans++, c.erase({x1 + a, y1 + b});
        if (c.count({x1 + a, y1 - b}))
            ans++, c.erase({x1 + a, y1 - b});
        if (c.count({x1 - a, y1 + b}))
            ans++, c.erase({x1 - a, y1 + b});
        if (c.count({x1 - a, y1 - b}))
            ans++, c.erase({x1 - a, y1 - b});
        cout << ans << '\n';
    }

    return 0;
}
