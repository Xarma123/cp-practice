#include <bits/stdc++.h>
#define lol long long
using namespace std;
pair<lol, lol> anchor;
bool cmp(pair<lol, lol> a, pair<lol, lol> b)
{
    if (a.second != b.second)
        return a.second <= b.second;
    else
        return a.first <= b.first;
}
bool cmp2(pair<lol, lol> a, pair<lol, lol> b)
{
    lol x1 = anchor.first;
    lol y1 = anchor.second;
    lol b1 = (a.first - x1) * 1ll * (a.first - x1);
    lol h1 = (a.first - x1) * 1ll * (a.first - x1) + (a.second - y1) * 1ll * (a.second - y1);
    lol b2 = (b.first - x1) * 1ll * (b.first - x1);
    lol h2 = (b.first - x1) * 1ll * (b.first - x1) + (b.second - y1) * 1ll * (b.second - y1);
    if (b1 * 1ll * h2 != b2 * 1ll * h1)
        return b1 * 1ll * h2 > b2 * 1ll * h1;
    else
        return h1 < h2;
}
int main()
{
    lol n;
    cin >> n;
    pair<lol, lol> points[n];
    for (lol i = 0; i < n; i++)
    {
        cin >> points[i].first >> points[i].second;
    }
    sort(points, points + n, cmp);

    anchor = points[0];

    sort(points, points + n, cmp2);
    cout << endl;
    for (lol i = 0; i < n; i++)
    {
        cout << points[i].first << " " << points[i].second << endl;
    }

    vector<pair<lol, lol>> ans;

    ans.push_back(points[0]);
    ans.push_back(points[1]);
    ans.push_back(points[2]);

    for (lol i = 3; i < n - 1; i++)
    {
        lol v = -1;
        while (v <= 0)
        {
            pair<lol, lol> x1 = ans[ans.size() - 2];
            pair<lol, lol> x2 = ans[ans.size() - 1];
            v = (points[i].second - x2.second) * 1ll * (x2.first - x1.first) - (points[i].first - x2.first) * 1ll * (x2.second - x1.second);
            if (v <= 0)
            {
                ans.pop_back();
            }
            if (ans.size() < 2)
                break;
        }

        ans.push_back(points[i]);
    }
    cout << ans.size() << endl;
    for (lol i = 0; i < ans.size(); i++)
    {
        cout << ans[i].first << " " << ans[i].second << endl;
    }

    return 0;
}