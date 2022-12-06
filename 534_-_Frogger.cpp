#include <bits/stdc++.h>
#define lol long double
using namespace std;
lol dis(pair<lol, lol> a, pair<lol, lol> b)
{
    return sqrtl(powl(a.first - b.first, 2) + powl(a.second - b.second, 2));
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long c = 1;
    while (1)
    {
        long long n;
        cin >> n;
        if (n == 0)
            break;
        pair<lol, lol> a[n];
        for (long long i = 0; i < n; i++)
        {
            cin >> a[i].first >> a[i].second;
        }
        lol dp[n][n];
        for (long long i = 0; i < n; i++)
        {
            for (long long j = 0; j < n; j++)
            {
                dp[i][j] = dis(a[i], a[j]);
            }
        }

        for (long long i = 0; i < n; i++)
        {
            for (long long j = 0; j < n; j++)
            {
                for (long long k = 0; k < n; k++)
                {

                    dp[j][k] = min(dp[j][k], max(dp[j][i], dp[i][k]));
                }
            }
        }

        cout << "Scenario #" << c << endl;
        c++;
        cout << "Frog Distance = " << fixed << setprecision(3) << dp[0][1] << endl;
        cout << endl;
    }

    return 0;
}