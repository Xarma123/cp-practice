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
    lol a[n];
    lol s = 0;
    lol od = -1;
    lol ptill = LONG_LONG_MAX;
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
        s += a[i];
        lol cp = 0;
        lol q = a[i];
        while (q % 2 == 0)
        {
            q /= 2;
            cp++;
        }
        if (cp < ptill)
        {
            ptill = cp;
            od = i;
        }
    }
    if (s % 2 == 0)
    {
        bool dp[s / 2 + 1][n + 1];
        for (lol i = 0; i <= s / 2; i++)
        {
            for (lol j = 0; j <= n; j++)
            {
                if (i == 0)
                    dp[i][j] = true;
                else if (j == 0)
                    dp[i][j] = false;
                else
                {
                    dp[i][j] = dp[i][j - 1];
                    if (i - a[j - 1] >= 0)
                        dp[i][j] |= dp[i - a[j - 1]][j - 1];
                }
            }
        }
        if (dp[s / 2][n])
        {
            cout << 1 << endl;
            cout << od + 1;
        }
        else
        {
            cout << 0;
        }
    }
    else
    {
        cout << 0;
    }

    return 0;
}