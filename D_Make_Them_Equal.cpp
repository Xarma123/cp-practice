#include <bits/stdc++.h>
#define lol long long
using namespace std;
lol knapSack(lol W, vector<lol> wt, vector<lol> val, lol n)
{
    lol i, w;
    lol K[n + 1][W + 1];

    for (i = 0; i <= n; i++)
    {
        for (w = 0; w <= W; w++)
        {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (wt[i - 1] <= w)
                K[i][w] = max(val[i - 1] +
                                  K[i - 1][w - wt[i - 1]],
                              K[i - 1][w]);
            else
                K[i][w] = K[i - 1][w];
        }
    }
    return K[n][W];
}
int main()
{
    lol T;
    cin >> T;
    while (T--)
    {
        lol n, k;
        cin >> n >> k;
        lol b[n];
        lol c[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> b[i];
        }
        for (lol i = 0; i < n; i++)
        {
            cin >> c[i];
        }
        lol op[n];
        for (lol i = 0; i < n; i++)
        {
            lol v = 1;
            lol c = 0;
            for (lol j = 1; v != b[i]; j++)
            {
                while (v / j + v <= b[i])
                {
                    c++;
                    v += v / j;
                }
            }
            op[i] = c;
        }
        lol ans = 0;
        vector<lol> wt;
        vector<lol> val;
        for (lol i = 0; i < n; i++)
        {
            if (op[i] == 0)
            {
                ans += c[i];
            }
            else
            {
                wt.push_back(op[i]);
                val.push_back(c[i]);
            }
        }

        cout << ans + knapSack(k, wt, val, wt.size()) << endl;
    }

    return 0;
}