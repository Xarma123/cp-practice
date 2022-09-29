#include <bits/stdc++.h>
#define lol long long
using namespace std;
lol n;
lol dp[1005][1005];
map<lol, lol> b;
map<lol, lol> f;
void solve(pair<lol, lol> a[], lol i, lol j)
{
    if (i >= j)
        return;
    if (i == j - 1)
    {
        return;
    }

    lol k;
    for (k = i; k < j; k++)
    {
        lol v = dp[i][k] + dp[k + 1][j];
        v += a[i].first * 1ll * a[k].second * 1ll * a[j].second;
        if (v == dp[i][j])
            break;
    }
    if (i != k)
    {
        b[i]++;
        f[k]++;
    }
    if (j != k + 1)
    {
        b[k + 1]++;
        f[j]++;
    }
    solve(a, i, k);
    solve(a, k + 1, j);
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol test = 1;
    while (1)
    {
        b.clear();
        f.clear();
        cin >> n;
        if (n == 0)
            break;
        pair<lol, lol> a[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i].first >> a[i].second;
        }
        for (lol len = 0; len < n; len++)
        {
            for (lol i = 0, j = len; j < n; i++, j++)
            {
                if (i > j)
                    dp[i][j] = 0;
                else if (i == j)
                {
                    dp[i][j] = 0;
                }
                else if (i == j - 1)
                {
                    dp[i][j] = a[i].first * 1ll * a[i].second * 1ll * a[j].second;
                }
                else
                {
                    dp[i][j] = LONG_LONG_MAX;
                    for (lol k = i; k < j; k++)
                    {

                        lol v = dp[i][k] + dp[k + 1][j];
                        v += a[i].first * 1ll * a[k].second * 1ll * a[j].second;
                        dp[i][j] = min(dp[i][j], v);
                    }
                }
            }
        }
       
        solve(a, 0, n - 1);
        cout << "Case " << test << ": "
             << "(";
        for (lol i = 1; i <= n; i++)
        {
            if (i != 1)
                cout << " x ";
            while (b[i-1]--)
                cout << "(";
            cout << "A" << i;
            while (f[i-1]--)
                cout << ")";
        }
        cout << ")";

        cout << endl;
        test++;
    }

    return 0;
}