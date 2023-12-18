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
        lol n;
        cin >> n;
        lol a[n][n];
        for (lol i = 0; i < n; i++)
        {
            for (lol j = 0; j < n; j++)
            {
                cin >> a[i][j];
            }
        }

        lol b[n];
        lol v = (1ll << 30ll) - 1;
        for (lol i = 0; i < n; i++)
        {
            b[i] = v;
        }

        for (lol i = 0; i < n; i++)
        {
            for (lol j = 0; j < n; j++)
            {
                if (i == j)
                    continue;
                for (lol k = 0; k < 30; k++)
                {
                    if ((a[i][j] & (1ll << k)) == 0)
                    {

                        if ((b[i] & (1ll << k)) != 0)
                            b[i] ^= (1ll << k);
                        if ((b[j] & (1ll << k)) != 0)
                            b[j] ^= (1ll << k);
                    }
                }
            }
        }
        bool ans = false;
        for (lol i = 0; i < n; i++)
        {
            for (lol j = 0; j < n; j++)
            {
                if (i == j)
                    continue;
                if (a[i][j] != (b[i] | b[j]))
                    ans = true;
            }
        }
        if (ans)
        {
            cout << "NO\n";
        }
        else
        {
            cout << "YES\n";
            for (lol i = 0; i < n; i++)
            {
                cout << b[i] << " ";
            }
            cout << '\n';
        }
    }

    return 0;
}
