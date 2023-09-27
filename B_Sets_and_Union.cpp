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
        lol n;
        cin >> n;
        bool v[n][51];
        for (lol i = 0; i < n; i++)
        {
            for (lol j = 0; j < 51; j++)
            {
                v[i][j] = false;
            }
        }
        bool all[51];
        memset(all, false, sizeof(all));
        for (lol i = 0; i < n; i++)
        {
            lol k;
            cin >> k;
            while (k--)
            {
                lol c;
                cin >> c;
                v[i][c] = true;
                all[c] = true;
            }
        }
        lol ans = 0;
        for (lol r = 0; r < 51; r++)
        {
            if (all[r])
            {
                lol c[51];
                memset(c, false, sizeof(c));
                for (lol i = 0; i < n; i++)
                {
                    if (v[i][r] == false)
                    {
                        for (lol j = 0; j < 51; j++)
                        {
                            c[j] |= v[i][j];
                        }
                    }
                }
                lol co = 0;
                for (lol i = 0; i < 51; i++)
                {
                    if (c[i])
                        co++;
                }
                ans = max(ans, co);
            }
        }
        cout << ans << '\n';
    }
}