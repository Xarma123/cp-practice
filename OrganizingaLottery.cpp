#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol s;
    cin >> s;
    lol p;
    cin >> p;
    vector<pair<lol, lol>> seg;
    for (lol i = 0; i < s; i++)
    {
        lol a, b;
        cin >> a >> b;
        seg.push_back(make_pair(a, b));
    }
    sort(seg.begin(), seg.end());
    for (lol i = 0; i < p; i++)
    {
        lol t, x, ans;
        x = INT_MAX;
        cin >> t;
        ans = 0;
        auto it = upper_bound(seg.begin(), seg.end(), make_pair(t,x));
        for (auto j = seg.begin(); j != it; j++)
        {
            if ((*j).second >= t)
            {
                ans++;
            }
        }
        cout << ans << " ";
    }

    return 0;
}