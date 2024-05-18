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
        lol x;
        cin >> x;
        for (lol i = 2; i <= x; i++)
        {
            if (x % i == 0)
            {
                if (1 + x - 1 < 2ll * (x / i))
                {
                    cout << x / i << '\n';
                }
                else
                    cout << x - 1 << '\n';
                break;
            }
        }
    }

    return 0;
}
