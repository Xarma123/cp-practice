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
        if (j < n)
        {
            while (a[j] == a[i])
            {
                j++;
                if (j == n)
                    break;
            }
        }
        v.push_back({a[i], j - i});
        i = j - 1;
    }
    lol dp[2][v.size()];
    for (lol i = 0; i < v.size(); i++)
    {
        if (i == 0)
        {
            dp[0][i] = v[i].first * 1ll * v[i].second;
            dp[1][i] = 0;
        }
        else if (v[i].first == v[i - 1].first + 1)
        {
            dp[0][i] = v[i].first * 1ll * v[i].second + dp[1][i - 1];
            dp[1][i] = max(dp[0][i - 1], dp[1][i - 1]);
        }
        else
        {
            dp[0][i] = v[i].first * 1ll * v[i].second + max(dp[0][i - 1], dp[1][i - 1]);
            dp[1][i] = max(dp[0][i - 1], dp[1][i - 1]);
        }
    } 
    cout<<max(dp[0][v.size()-1],dp[1][v.size()-1]);

    return 0;
}