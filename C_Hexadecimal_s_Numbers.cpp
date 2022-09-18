#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol n;
    cin >> n;
    lol ans = 0;
    for (lol i = 1; i <= pow(2, 10) - 1; i++)
    {
        lol t = 0, t2 = 1;
        for (lol j = 0; j < 10; j++)
        {
            if ((i >> j) & 1)
                t += t2 * 1;

            t2 = t2 * 10;
        }
        if (1 <= t && t <= n)
            ans++;
    }

    cout << ans << endl;
    return 0;
}