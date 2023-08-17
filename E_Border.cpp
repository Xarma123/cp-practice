#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, k;
    cin >> n >> k;
    lol b[n];
    vector<lol> a;
    for (lol i = 0; i < n; i++)
    {
        cin >> b[i];
        b[i] %= k;
        lol c = 10;
        lol v = b[i];
        while (c--)
        {
            a.push_back(b[i]);
            b[i] += v;
            b[i] %= k;
        }
    }
    sort(a.begin(), a.end());
    lol dp[10];
    for (lol i = 0; i < 10; i++)
    {
        dp[i] = LONG_LONG_MAX;
    }
    for (lol i = 0; i < a.size(); i++)
    {
        dp[(a[i] % 10)] = min(dp[(a[i] % 10)], a[i]);
        for (lol j = 0; j < 10; j++)
        {
            if (dp[j] != LONG_LONG_MAX)
            {
                dp[(((dp[j] + a[i]) % k) % 10)] = min(((dp[j] + a[i]) % k), dp[(((dp[j] + a[i]) % k) % 10)]);
            }
        }
    }
    lol c = 0;
    for (lol i = 0; i < 10; i++)
    {
        if (dp[i] != LONG_LONG_MAX)
            c++;
    }
    cout << c << '\n';
    for (lol i = 0; i < 10; i++)
    {
        if (dp[i] != LONG_LONG_MAX)
            cout << i << " ";
    }
}