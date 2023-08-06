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
        vector<pair<lol, lol>> v;
        lol a = 0, b = 0, c = 0, d = 0;
        for (lol i = 0; i < n; i++)
        {
            lol x, y;
            cin >> x >> y;
            v.push_back({x, y});
            if (y == 0 && x > 0)
            {
                a = max(a, x);
            }
            if (x == 0 && y > 0)
            {
                b = max(b, y);
            }
            if (y == 0 && x < 0)
            {

                c = max(c, -x);
            }
            if (x == 0 && y < 0)
            {
                d = max(d, -y);
            }
        }
        cout << 2ll * (a + b + c + d) << '\n';
    }
}