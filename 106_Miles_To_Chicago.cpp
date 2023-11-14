#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    while (1)
    {
        lol n;
        cin >> n;
        if (n == 0)
            break;
        lol m;
        cin >> m;
        vector<vector<lol>> ed;
        while (m--)
        {
            lol a, b, c;
            cin >> a >> b >> c;
            ed.push_back({a, b, c});
        }
        long double d[n + 1];
        for (lol i = 0; i <= n; i++)
        {
            d[i] = DBL_MIN;
        }
        d[1] = 1;
        for (lol i = 0; i < n - 1; i++)
        {
            for (auto e : ed)
            {
                if (d[e[0]] != DBL_MIN)
                {
                    d[e[1]] = max(d[e[1]], d[e[0]] * (e[2] / (long double)100));
                }
                if (d[e[1]] != DBL_MIN)
                {
                    d[e[0]] = max(d[e[0]], d[e[1]] * (e[2] / (long double)100));
                }
               
            }
        }
        cout << fixed << setprecision(6) << (d[n] * (long double)100) << " percent\n";
    }

    return 0;
}
