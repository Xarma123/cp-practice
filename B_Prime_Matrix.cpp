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
    lol a[n][m];
    for (lol i = 0; i < n; i++)
    {
        for (lol j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }
    bool prime[1000000];
    memset(prime, true, sizeof(prime));
    vector<lol> p;
    for (lol i = 2; i < 1000000; i++)
    {
        if (prime[i])
        {
            p.push_back(i);
            for (lol j = i * 1ll * i; j < 1000000; j += i)
            {
                prime[j] = false;
            }
        }
    }

    for (lol i = 0; i < n; i++)
    {
        for (lol j = 0; j < m; j++)
        {
            lol k = lower_bound(p.begin(), p.end(), a[i][j]) - p.begin();
            a[i][j] = p[k] - a[i][j];
        }
    }
    lol ans = LONG_LONG_MAX;
    for (lol i = 0; i < n; i++)
    {
        lol v = 0;
        for (lol j = 0; j < m; j++)
        {
            v += a[i][j];
        }
        ans = min(ans, v);
    }
    for (lol j = 0; j < m; j++)
    {
        lol v = 0;
        for (lol i = 0; i < n; i++)
        {
            v += a[i][j];
        }
        ans = min(ans, v);
    }
    cout << ans;

    return 0;
}