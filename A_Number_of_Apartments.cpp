#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        lol n;
        cin >> n;
        bool ans = false;
        lol x, y;
        for (x = 0; x <= n; x++)
        {
            for (y = 0; y <= n; y++)
            {
                if ((n - 3 * x - 5 * y) >= 0 && (n - 3 * x - 5 * y) % 7 == 0)
                {
                    ans = true;
                    break;
                }
            }
            if (ans)
                break;
        }
        if (ans)
        {
            cout << x << " " << y << " " << (n - 3 * x - 5 * y) / 7 << endl;
        }
        else
            cout << -1 << endl;
    }

    return 0;
}