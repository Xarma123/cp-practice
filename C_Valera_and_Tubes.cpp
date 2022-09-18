#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, m, k;
    cin >> n >> m >> k;
    lol K = k;
    bool f = false;
    lol tgle = 0;
    bool used[n][m];
    memset(used, false, sizeof(used));
    for (lol i = 1; i <= n; i++)
    {
        for (lol q = 1; q <= m; q++)
        {
            lol j;
            if (tgle)
            {
                j = m - q + 1;
            }
            else
            {
                j = q;
            }
            if (used[i - 1][j - 1])
                continue;
            if (k > 1)
            {
                cout << 2 << " " << i << " " << j << " ";
                if (tgle)
                {
                    if (j > 1)
                    {
                        cout << i << " " << j - 1 << endl;
                        used[i - 1][j - 2] = true;
                    }
                    else
                    {
                        cout << i + 1 << " " << j << endl;
                        used[i][j - 1] = true;
                    }
                }
                else
                {
                    if (j < m)
                    {
                        cout << i << " " << j + 1 << endl;
                        used[i - 1][j] = true;
                    }
                    else
                    {
                        cout << i + 1 << " " << j << endl;
                        used[i][j - 1] = true;
                    }
                }
                k--;
            }
            else if (!f)
            {
                cout << n * m - 2*1ll*(K - 1) << " " << i << " " << j;
                f = true;
            }
            else
                cout << " " << i << " " << j;
        }
        tgle = 1 - tgle;
    }
    cout << endl;

    return 0;
}