#include <bits/stdc++.h>
#define lol long long
using namespace std;
vector<vector<lol>> c;
bool check(lol x, lol y, lol i)
{
    return (powl(x - c[i][0], 2) + powl(y, 2) <= powl(c[i][1], 2));
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n;
    cin >> n;
   
    for (lol i = 0; i < n; i++)
    {
        lol x, r;
        cin >> x >> r;
        c.push_back({x, r, i});
    }
    sort(c.begin(), c.end());
    lol m;
    cin >> m;
    vector<lol> ans(n, -1);
    lol q = 0;
    lol p = 1;
    while (m--)
    {
        lol x, y;
        cin >> x >> y;
        vector<lol> h;
        h.push_back(x);
        h.push_back(LONG_LONG_MIN);
        h.push_back(LONG_LONG_MIN);
        lol i = upper_bound(c.begin(), c.end(), h) - c.begin();
        if (i >= 0 && i < n)
        {
            if (check(x, y, i))
            {
                if (ans[c[i][2]] == -1)
                {
                    q++;
                    ans[c[i][2]] = p;
                }
            }
        }
        i--;
        if (i >= 0 && i < n)
        {
            if (check(x, y, i))
            {
                if (ans[c[i][2]] == -1)
                {
                    q++;
                    ans[c[i][2]] = p;
                }
            }
        }
        p++;
    }
    cout << q << endl;
    for (lol i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}