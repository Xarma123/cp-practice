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
    lol p = 1;
    while (t--)
    {
        lol n, m;
        cin >> n >> m;
        lol d[n];
        lol par[n];
        for (lol i = 0; i < n; i++)
        {
            par[i] = -1;
            d[i] = LONG_LONG_MAX;
        }
        d[0] = 0;
        vector<vector<lol>> edg;
        while (m--)
        {
            lol a, b, c;
            cin >> a >> b >> c;
            if (a >= 0 && a < n && b >= 0 && b < n && a != b)
            {
                edg.push_back({a, b, c});
            }
        }

        for (lol k = 0; k < n - 1; k++)
        {
            for (auto e : edg)
            {
                if (d[e[0]] != LONG_LONG_MAX && d[e[0]] + e[2] < d[e[1]])
                {
                    d[e[1]] = d[e[0]] + e[2];
                    par[e[1]] = e[2];
                }
            }
        }
        bool q = true;
        lol ans = 0;
        for (lol i = 1; i < n; i++)
        {
            if (par[i] == -1)
            {
                q = false;
                break;
            }
            else
            {
                ans += par[i];
            }
        }
        cout << "Case #" << p << ": ";
        if (q)
            cout << ans;
        else
            cout << "Possums!";

        cout << '\n';
        p++;
    }

    return 0;
}
