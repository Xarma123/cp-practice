#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, m;
    cin >> n >> m;
    lol f[n][n];
    memset(f, 0, sizeof(f));
    while (m--)
    {
        lol a, b, c;
        cin >> a >> b >> c;
        f[a - 1][b - 1] = c;
    }
    for (lol c = 0; c < n; c++)
        for (lol i = 0; i < n; i++)
        {
            for (lol j = 0; j < n; j++)
            {
                for (lol k = 0; k < n; k++)
                {
                    if (f[i][j] && f[j][k])
                    {
                        lol d = min(f[i][j], f[j][k]);
                        f[i][k] += d;
                        f[i][j] -= d;
                        f[j][k] -= d;
                    }
                }
            }
        }
    lol ans = 0;
    for (lol i = 0; i < n; i++)
    {
        for (lol j = 0; j < n; j++)
        {
            ans += f[i][j];
        }
    }
    cout << ans;

    return 0;
}