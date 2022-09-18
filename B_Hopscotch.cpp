#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol a, x, y;
    cin >> a >> x >> y;
    if (y % a == 0)
    {
        cout << -1;
    }
    else
    {
        lol v = y / a;

        if (v != 0 && v % 2 == 0)
        {
            if (x >= a || x <= -a || x == 0)
            {
                cout << -1;
            }
            else if (x < 0)
            {

                cout << 3 + (v / 2 - 1) * 1ll * 3;
            }
            else
            {
                cout << 3 + (v / 2 - 1) * 1ll * 3 + 1;
            }
        }
        else
        {
            if (2 * x >= a || 2 * x <= -a)
            {
                cout << -1;
            }
            else
            {
                if (y < a)
                    cout << 1;
                else if (y < 2 * a)
                    cout << 2;
                else
                {
                    cout << 2 + (v / 2) * 1ll * 3;
                }
            }
        }
    }

    return 0;
}