#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    lol hy, aty, dy;
    cin >> hy >> aty >> dy;
    lol hm, atm, dm;
    cin >> hm >> atm >> dm;
    lol h, at, d;
    cin >> h >> at >> d;
    lol ans = LONG_LONG_MAX;
    for (lol i = aty; i <= aty + 200; i++)
    {
        for (lol j = dy; j <= dy + 200; j++)
        {
            if (i - dm <= 0)
            {
                continue;
            }
            else
            {
                lol time = hm / (i - dm) + ((hm % (i - dm)) > 0);

                lol a = (i - aty) * at + (j - dy) * d;

                if (atm - j > 0)
                {
                    lol t2 = hy / (atm - j) + ((hy % (atm - j)) > 0);

                    if (t2 <= time)
                    {
                        lol ex = atm - j - (hy % (atm - j));
                        while (t2 <= time)
                        {
                            ex += atm - j;
                            t2++;
                        }
                        if (atm - j > 1)
                            ex -= atm - j - 1;
                        a += ex * h;
                    }
                }
                ans = min(ans, a);
            }
        }
    }
    cout << ans;

    return 0;
}