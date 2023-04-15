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
        lol n, k;
        cin >> n >> k;
        lol a[n][n];
        for (lol i = 0; i < n; i++)
        {
            for (lol j = 0; j < n; j++)
            {
                cin >> a[i][j];
            }
        }
        lol b = n - 1;
        lol v = 0;
        for (lol i = 0; b >= i; i++)
        {
            for (lol j = 0; j < n; j++)
            {
                if (i == b && j >= n / 2)
                    break;
                if (a[i][j] != a[b][n - j - 1])
                {
                    v++;
                }
            }
            b--;
        }
        if (k >= v && ((k - v) % 2 == 0))
            cout << "YES\n";
        else if (k >= v && (n % 2 == 1))
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}