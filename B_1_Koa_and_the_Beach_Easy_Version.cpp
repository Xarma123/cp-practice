#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol t;
    cin >> t;
    while (t--)
    {
        lol n, k, l;
        cin >> n >> k >> l;
        lol d[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> d[i];
        }
        lol c[2ll * k];
        c[0] = 0;
        for (lol i = 0; i <= k; i++)
        {
            c[i] = i;
        }
        for (lol i = k + 1; i < 2ll * k; i++)
        {
            c[i] = c[i - 1] - 1;
        }
        bool dp[n][2ll * k];
        for (lol i = 0; i < n; i++)
        {
            for (lol j = 0; j < 2ll * k; j++)
            {
                if (d[i] + c[j] <= l)
                    dp[i][j] = true;
                else
                    dp[i][j] = false;
                if (i)
                {
                    lol q = j - 1;
                    if (q < 0)
                        q = 2 * k - 1;
                    if (dp[i - 1][q] != true)
                        dp[i][j] = false;
                }
            }
            for (lol j = 0; j < 2 * k; j++)
            {
                if (dp[i][j])
                {
                    lol q = (j + 1) % (2 * k);
                    while (d[i] + c[q] <= l && dp[i][q] == false)
                    {
                        dp[i][q] = true;
                        q++;
                        q %= 2ll * k;
                    }
                    if (q > j)
                        j = q - 1;
                }
            }
        }
        bool ans = false;
        for (lol i = 0; i < 2ll * k; i++)
        {
            ans |= dp[n - 1][i];
        }
        if (ans)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
}