#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n;
    cin >> n;
    lol a[n];
    lol m = 998244353;
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    lol ans = 0;
    for (lol b = 0; b < 31; b++)
    {
        lol c[n];
        for (lol j = 0; j < n; j++)
        {
            c[j] = ((a[j] & (1ll << b))>0);
        }

        lol sum[n][2];
        lol co[n][2];

        for (lol i = 0; i < n; i++)
        {
            // cout<<c[i]<<" ";
            if (c[i] == 1)
            {
                co[i][1] = 1;
                co[i][0] = 0;
                sum[i][1] = 1;
                sum[i][0] = 0;
            }
            else
            {
                co[i][0] = 1;
                co[i][1] = 0;
                sum[i][0] = 1;
                sum[i][1] = 0;
            }
            if (i)
            {
                if (c[i] == 1)
                {
                    sum[i][1] += (sum[i - 1][0] + co[i - 1][0]) % m;
                    sum[i][0] += (sum[i - 1][1] + co[i - 1][1]) % m;
                    co[i][1] += co[i - 1][0];
                    co[i][0] += co[i - 1][1];
                }
                else
                {
                    sum[i][0] += (sum[i - 1][0] + co[i - 1][0]) % m;
                    sum[i][1] += (sum[i - 1][1] + co[i - 1][1]) % m;
                    co[i][0] += co[i - 1][0];
                    co[i][1] += co[i - 1][1];
                }
            }
            sum[i][0] %= m;
            sum[i][1] %= m;
            co[i][0] %= m;
            co[i][1] %= m;
            ans += (sum[i][1] * 1ll * (1ll << b)) % m;
            ans %= m;
            // cout << sum[i][1] << " ";
        }
        cout << endl;
    }
    cout << ans;
}