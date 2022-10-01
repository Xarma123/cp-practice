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
    lol c[n][n];
    lol ans = 0;
    for (lol i = 0; i < n; i++)
    {
        for (lol j = 0; j < n; j++)
        {
            cin >> c[i][j];
            if (i == j)
                ans += c[i][j];
        }
    }
    ans %= 2;
    lol q;
    cin >> q;
    while (q--)
    {
        lol t;
        cin >> t;
        if (t == 1)
        {
            lol i;
            cin >> i;
            i--;
            if (c[i][i] == 1)
            {
                ans = (ans - 1 + 2) % 2;
            }
            else
                ans = (ans + 1) % 2;
            c[i][i] = 1 - c[i][i];
        }
        else if (t == 2)
        {
            lol i;
            cin >> i;
            i--;
            if (c[i][i] == 1)
            {
                ans = (ans - 1 + 2) % 2;
            }
            else
                ans = (ans + 1) % 2;
            c[i][i] = 1 - c[i][i];
        }
        else
        {
            cout << ans;
        }
    }

    return 0;
}