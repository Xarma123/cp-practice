#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol t;
    cin >> t;
    while (t--)
    {
        lol n, m, x;
        cin >> n >> m >> x;
        bool dp[n][m + 1];
        memset(dp, false, sizeof(dp));
        dp[x - 1][0] = true;
        for (lol j = 0; j < m; j++)
        {
            lol r;
            cin >> r;
            char c;
            cin >> c;
            for (lol i = 0; i < n; i++)
            {
                if (dp[i][j])
                {
                    if (c == '1')
                    {
                        dp[((i - r + n) % n)][j + 1] = true;
                    }
                    else if (c == '0')
                    {
                        dp[((i + r) % n)][j + 1] = true;
                    }
                    else
                    {
                        dp[((i - r + n) % n)][j + 1] = true;
                        dp[((i + r) % n)][j + 1] = true;
                    }
                }
            }
        }
        vector<lol> v;
        for (lol i = 0; i < n; i++)
        {
            if (dp[i][m])
                v.push_back((i + 1));
        }
        cout << v.size() << '\n';
        for (auto e : v)
            cout << e << " ";
        cout << '\n';
    }

    return 0;
}
