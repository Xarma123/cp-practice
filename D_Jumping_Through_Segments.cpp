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
        lol n;
        cin >> n;
        vector<vector<lol>> v;
        for (lol i = 0; i < n; i++)
        {
            lol a, b;
            cin >> a >> b;
            v.push_back({a, b});
        }
        lol st = -1, e = 1e12;
        while (st != e - 1)
        {

            lol m = (st + e) / 2ll;
            if (m == -1)
            {
                st = m;
                continue;
            }
            lol l = -m, r = m;
            lol i;
            for (i = 0; i < n; i++)
            {
                l = max(l, v[i][0]);
                r = min(r, v[i][1]);
                if (l > r)
                {
                    break;
                }
                l = l - m;
                r = r + m;
            }
            if (i < n)
                st = m;
            else
                e = m;
        }
        cout << e << '\n';
    }

    return 0;
}
