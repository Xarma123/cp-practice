#include <bits/stdc++.h>
#define lol int
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol t;
    cin >> t;
    while (t--)
    {
        lol n;
        cin >> n;
        lol a[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        lol ans = 0;
        lol p[n + 1][27];
        memset(p, 0, sizeof(p));
        for (lol i = 0; i < n; i++)
        {
            if (i == 0)
            {
                p[i + 1][a[i]]++;
            }
            else
            {
                for (lol k = 0; k < 27; k++)
                {
                    p[i + 1][k] += p[i][k];
                }
                p[i + 1][a[i]]++;
            }
        }

        for (lol i = 0; i < n; i++)
        {
            for (lol j = i; j < n; j++)
            {
                for (lol k1 = 0; k1 < 27; k1++)
                {
                    ans = max(ans, p[i + 1][k1]);
                    for (lol k = 0; k < 27; k++)
                    {
                        if (i - 1 >= 0 && j + 1 < n)
                            ans = max(ans, 2 * min(p[i][k], p[n][k] - p[j + 1][k]) + p[j + 1][k1] - p[i][k1]);
                    }
                }
            }
        }
        cout << ans << '\n';
    }

    return 0;
}