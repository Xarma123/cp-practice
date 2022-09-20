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
    set<lol> x;
    for (lol i = 1; i <= n; i++)
    {
        x.insert(i);
    }
    lol ans[n];
    memset(ans, 0, sizeof(ans));
    while (m--)
    {
        lol l, r, w;
        cin >> l >> r >> w;
        auto it = x.lower_bound(l);
        while (it != x.end())
        {
            if ((*it) > r)
                break;
            if ((*it) != w)
            {
                ans[(*it) - 1] = w;
            }
            it++;
        }
        it = x.lower_bound(l);
        while (it != x.end())
        {
            if ((*it) > r)
                break;
            auto y = it;
            y++;
            if ((*it) != w)
                x.erase(it);
            it = y;
        }
    }
    for (lol i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}