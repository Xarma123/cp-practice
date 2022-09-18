#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol t, k;
    cin >> t >> k;

    vector<lol> dp(100005, 0);
    lol m = 1e9 + 7;
    dp[0] = 1;
    lol c[dp.size() + 1];
    c[0] = 0;
    for (lol i = 1; i < dp.size(); i++)
    {
        dp[i] = (dp[i] + dp[i - 1]) % m;
        if (i - k >= 0)
            dp[i] = (dp[i] + dp[i - k]) % m;
        c[i + 1] = (c[i] + dp[i]) % m;
    }

    while (t--)
    {
        lol a, b;
        cin >> a >> b;
        cout << (c[b + 1] - c[a] + m) % m << endl;
    }

    return 0;
}