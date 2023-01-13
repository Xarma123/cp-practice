#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, k;
    cin >> n >> k;
    if (n < 2)
    {
        if (k == 0)
        {
            cout << 1;
        }
        else
            cout << -1;
    }
    else
    {
        if (k - ((n - 2) / 2) > 0)
        {
            cout << k - ((n - 2) / 2) << " " << 2ll * (k - ((n - 2) / 2)) << " ";
            for (lol i = 3; i <= n; i++)
            {
                cout << 2ll * (k - ((n - 2) / 2)) + 1 + i - 3 << ' ';
            }
        }
        else
            cout << -1;
    }

    return 0;
}