#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, sup;
    lol chain = 1;
    while (1)
    {

        cin >> n >> sup;
        if (n == 0 && sup == 0)
            break;
        cout << "Chain " << chain << endl;
        chain++;
        lol d[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> d[i];
        }
        sort(d, d + n);
        lol sum[n][n];
        for (lol i = 0; i < n; i++)
        {
            for (lol j = i; j < n; j++)
            {

                lol v = 0;
                for (lol k = i; k <= j; k++)
                {
                    v += abs(d[i + (j - i) / 2] - d[k]);
                }
                sum[i][j] = v;
            }
        }
        lol dp[n][sup + 1];
        vector<lol> in[n][sup + 1];
        for (lol i = 0; i < n; i++)
        {
            dp[i][1] = sum[0][i];
            in[i][1].push_back(i / 2);
        }

        for (lol k = 2; k <= sup; k++)
        {
            for (lol i = 0; i < n; i++)
            {
                if (i == 0)
                    dp[i][k] = 0;
                else
                {
                    dp[i][k] = LONG_LONG_MAX;
                    for (lol j = 0; j < i; j++)
                    {
                        if (dp[i][k] > dp[j][k - 1] + sum[j + 1][i])
                        {
                            in[i][k] = in[j][k - 1];
                            in[i][k].push_back(j + 1 + (i - j - 1) / 2);

                            dp[i][k] = dp[j][k - 1] + sum[j + 1][i];
                        }
                    }
                }
            }
        }
        lol p = 0, i = 0;
        while (p < in[n - 1][sup].size() && i < n)
        {
            lol st = i;
            while (p + 1 >= in[n - 1][sup].size() || (p + 1 < in[n - 1][sup].size() && abs(d[in[n - 1][sup][p]] - d[i]) < abs(d[in[n - 1][sup][p + 1]] - d[i])))
            {
                i++;
                if (i == n)
                    break;
            }
            if (st + 1 != i)
                cout << "Depot " << p + 1 << " at restaurant " << in[n - 1][sup][p] + 1 << " serves restaurants " << st + 1 << " to " << i << endl;
            else
                cout << "Depot " << p + 1 << " at restaurant " << in[n - 1][sup][p] + 1 << " serves restaurant " << st + 1 << endl;
            p++;
        }

        cout << "Total distance sum = " << dp[n - 1][sup] << endl;
        cout << endl;
    }

    return 0;
}