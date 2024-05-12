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
        lol n, x;
        cin >> n >> x;
        lol p[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> p[i];
        }
        vector<vector<lol>> ans;
        if (p[0] > x)
        {
            for (lol i = 0; i < n; i++)
            {
                if (p[i] <= x)
                {
                    ans.push_back({1, i + 1});
                    swap(p[i], p[0]);
                    break;
                }
            }
        }
        lol l = 1, r = n + 1;
        while (r - l != 1)
        {
            lol m = (r + l) / 2ll;
            if (m == n + 1)
            {
                r = m;
            }
            else if (p[m - 1] <= x)
            {
                l = m;
            }
            else
                r = m;
        }
        for (lol i = 0; i < n; i++)
        {
            if (p[i] == x)
            {
                ans.push_back({l, i + 1});
                break;
            }
        }
        cout << ans.size() << '\n';
        for (auto e : ans)
        {
            cout << e[0] << " " << e[1] << '\n';
        }
    }

    return 0;
}
