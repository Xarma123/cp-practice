#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n;
    cin >> n;
    lol d[n][n];
    for (lol i = 0; i < n; i++)
    {
        for (lol j = 0; j < n; j++)
        {
            cin >> d[i][j];
        }
    }
    vector<lol> q(n, 0);
    for (lol i = 0; i < n; i++)
    {
        cin >> q[i];
    }
    stack<lol> x;
    bool y[n];
    memset(y, false, sizeof(y));
    for (lol i = n - 1; i >= 0; i--)
    {
        lol r = q[i] - 1;
        y[r] = true;
        lol ans = 0;
        for (lol j = 0; j < n; j++)
        {
            for (lol k = 0; k < n; k++)
            {

                d[j][k] = min(d[j][k], d[j][r] + d[r][k]);

                if (y[j] && y[k])
                    ans += d[j][k];
            }
        }
        x.push(ans);
    }
    while (!x.empty())
    {
        cout << x.top() << " ";
        x.pop();
    }

    return 0;
}