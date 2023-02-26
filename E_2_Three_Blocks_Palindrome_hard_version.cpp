#include <bits/stdc++.h>
#define lol long long
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
        lol p[n + 1][201];
        memset(p, 0, sizeof(p));
        for (lol i = 0; i < n; i++)
        {
            if (i == 0)
            {
                p[i + 1][a[i]]++;
            }
            else
            {
                p[i + 1][a[i]]++;
                for (lol k = 0; k < 201; k++)
                {
                    p[i + 1][k] += p[i][k];
                }
            }
            for (lol k = 0; k < 201; k++)
            {
                ans = max(ans, p[i + 1][k]);
            }
        }
        lol i = 0, j = n - 1;
        while (i < j - 1)
        {

            lol m = 0;
            lol l = 0;
            bool f = false;
            for (lol k = 0; k < 201; k++)
            {
                m = max(m, p[j][k] - p[i + 1][k]);

                if (l < min(p[i + 1][k], p[n][k] - p[j][k]))
                {
                    l = min(p[i + 1][k], p[n][k] - p[j][k]);
                    if (p[i + 1][k] <= p[n][k] - p[j][k])
                        f = true;
                    else
                        f = false;
                }
            }
            if (f)
                i++;
            else
                j--;
            ans = max(ans, 2ll * l + m);
        }

        cout << ans << '\n';
    }

    return 0;
}