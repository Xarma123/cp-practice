#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol q;
    cin >> q;
    while (q--)
    {
        lol a1, b1, c1;
        cin >> a1 >> b1 >> c1;
        lol ans = LONG_LONG_MAX;
        for (lol i = a1 - 1; i <= a1 + 1; i++)
        {
            for (lol j = b1 - 1; j <= b1 + 1; j++)
            {
                for (lol k = c1 - 1; k <= c1 + 1; k++)
                {
                    ans = min(ans, abs(i - j) + abs(i - k) + abs(j - k));
                }
            }
        }
        cout << ans << endl;
    }

    return 0;
}