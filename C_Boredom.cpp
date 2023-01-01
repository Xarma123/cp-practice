#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n;
    cin >> n;
    lol a[n];
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n);
    vector<pair<lol, lol>> v;
    for (lol i = 0; i < n; i++)
    {
        lol j = i + 1;
        while (j < n && a[j] == a[i])
        {
            j++;
        }
        v.push_back({a[i], j - i});
        i = j - 1;
    }
    lol dp[v.size() + 1];
    dp[0] = 0;
    for (lol i = 0; i < v.size(); i++)
    {
        if (i == 0)
        {
            dp[i + 1] = v[i].first * 1ll * v[i].second;
        }
        else
        {
            dp[i + 1] = dp[i];
            if (v[i - 1].first == v[i].first - 1)
            {
                dp[i + 1] = max(dp[i + 1], v[i].first * 1ll * v[i].second + dp[i - 1]);
            }
            else
            {
                dp[i + 1] += v[i].first * 1ll * v[i].second;
            }
        }
    }
    cout << dp[v.size()];

    return 0;
}