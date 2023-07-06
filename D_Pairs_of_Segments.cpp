#include <bits/stdc++.h>
using namespace std;
#define lol long long
bool cmp(pair<lol, lol> a, pair<lol, lol> b)
{
    return a.second < b.second;
}
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        lol n;
        cin >> n;
        pair<lol, lol> a[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i].first >> a[i].second;
        }
        vector<pair<lol, lol>> v;
        for (lol i = 0; i < n; i++)
        {
            for (lol j = i + 1; j < n; j++)
            {
                if (!(a[i].first > a[j].second || a[i].second < a[j].first))
                {
                    v.push_back({min(a[i].first, a[j].first), max(a[i].second, a[j].second)});
                }
            }
        }
        if (v.size() == 0)
        {
            cout << n << '\n';
        }
        else
        {
            sort(v.begin(), v.end(), cmp);
            lol dp[v.size()];
          
            for (lol i = 0; i < v.size(); i++)
            {

                if (i == 0)
                {
                    dp[i] = 1;
                }
                else
                {
                    lol s = -1, e = i;
                    while (s != e - 1)
                    {
                        lol m = (s + e) / 2;
                        if (m == -1)
                            s = m;
                        else if (v[m].second < v[i].first)
                            s = m;
                        else
                            e = m;
                    }
                    if (s >= 0)
                        dp[i] = dp[s] + 1;
                    else
                        dp[i] = 1;

                    dp[i] = max(dp[i - 1], dp[i]);
                  
                }
            }
            cout << n - 2ll * dp[v.size() - 1] << '\n';
        }
    }
}