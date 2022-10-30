#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, m;
    cin >> n >> m;
    vector<lol> v;
    for (lol i = 0; i < n; i++)
    {
        lol e;
        cin >> e;
        v.push_back(e);
    }
    sort(v.begin(), v.end());
    vector<lol> q;
    lol ans = LONG_LONG_MAX;
    lol c = 0;
    while (m--)
    {
        lol x, y, r;
        cin >> x >> y >> r;
        if (x == 1)
        {
            if (y == 1e9)
            {
                c++;
            }
            else
            {
                lol i = upper_bound(v.begin(), v.end(), y) - v.begin();
                if (i)
                    q.push_back(i);
            }
        }
    }

    sort(q.rbegin(), q.rend());
    for (lol i = 0; i < q.size(); i++)
    {
        ans = min(ans, i + q[i] + c);
        if (i == q.size() - 1)
        {
            ans = min(ans, i + 1 + c);
        }
    }
    if (ans == LONG_LONG_MAX)
        ans = c;
    cout << ans;

    return 0;
}