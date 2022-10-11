#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, x;
    cin >> n >> x;

    vector<vector<lol>> seg;
    for (lol i = 0; i < n; i++)
    {
        lol l, r, c;
        cin >> l >> r >> c;
        seg.push_back({l, r, c});
    }
    sort(seg.begin(), seg.end());
    map<lol, lol> mn;
    set<vector<lol>> q;
    lol ans = LONG_LONG_MAX;
    for (auto e : seg)
    {

        while (!q.empty() && (*q.begin())[0] < e[0])
        {
            if (mn.count((*q.begin())[0] - (*q.begin())[1] + 1))
                mn[(*q.begin())[0] - (*q.begin())[1] + 1] = min(mn[(*q.begin())[0] - (*q.begin())[1] + 1], (*q.begin())[2]);
            else
                mn[(*q.begin())[0] - (*q.begin())[1] + 1] = (*q.begin())[2];
            q.erase(q.begin());
        }
        lol c = e[2];
        lol v = e[1] - e[0] + 1;
        v = x - v;
        if (mn.count(v))
        {
            ans = min(ans, c + mn[v]);
        }

        q.insert({e[1], e[0], e[2]});
    }
    if (ans == LONG_LONG_MAX)
        cout << -1;
    else
        cout << ans;

    return 0;
}