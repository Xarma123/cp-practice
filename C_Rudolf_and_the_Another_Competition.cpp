#include <bits/stdc++.h>
using namespace std;
#define lol long long
bool cmp(pair<lol, pair<lol, lol>> a, pair<lol, pair<lol, lol>> b)
{
    if (a.first > b.first)
        return true;
    if (a.first < b.first)
        return false;
    if (a.second.first < b.second.first)
        return true;
    if (a.second.first > b.second.first)
        return false;
    return a.second.second <= b.second.second;
}
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        lol n, m, h;
        cin >> n >> m >> h;
        vector<vector<lol>> a(n, vector<lol>(m));
        for (lol i = 0; i < n; i++)
        {
            for (lol j = 0; j < m; j++)
            {
                cin >> a[i][j];
            }
        }

        vector<pair<lol, pair<lol, lol>>> v;
        for (lol i = 0; i < n; i++)
        {
            sort(a[i].begin(), a[i].end());
            lol c = 0, s = 0;
            lol p = 0;
            for (lol j = 0; j < m; j++)
            {

                if (a[i][j] + s <= h)
                {
                    c++;
                    s += a[i][j];
                    p += s;
                }
                else
                    break;
            }
            v.push_back({c, {p, i}});
        }

        sort(v.begin(), v.end(), cmp);
        for (lol i = 0; i < v.size(); i++)
        {
            if (v[i].second.second == 0)
            {
                cout << i + 1 << '\n';
                break;
            }
        }
    }
}