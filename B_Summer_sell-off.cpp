#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, f;
    cin >> n >> f;
    lol ans = 0;
    vector<pair<lol, lol>> x;
    vector<pair<lol, lol>> y;
    while (n--)
    {
        lol a, b;
        cin >> a >> b;
        if (a >= b)
        {
            ans += b;
        }
        else
        {
            x.push_back({a, b});
            y.push_back({min(2 * 1ll * a, b) - a, x.size() - 1});
        }
    }
    bool use[x.size()];
    memset(use, false, sizeof(use));
    sort(y.begin(), y.end());
    while (f--)
    {
        if (!y.size())
            break;
        use[y.back().second] = true;
        ans += y.back().first + x[y.back().second].first;
        y.pop_back();
    }
    for (lol i = 0; i < x.size(); i++)
    {
        if (!use[i])
            ans += x[i].first;
    }
    cout << ans;

    return 0;
}