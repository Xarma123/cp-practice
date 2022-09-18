#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol T;
    cin >> T;
    while (T--)
    {
        lol p, q;
        cin >> p >> q;
        lol q1 = q;
        if (p % q != 0)
        {
            cout << p << endl;
        }
        else
        {
            map<lol, lol> fact;

            for (lol i = 2; i * i <= q; i++)
            {
                while (q % i == 0)
                {
                    fact[i]++;
                    q /= i;
                }
            }
            if (q > 1)
                fact[q]++;
            lol ans = LONG_LONG_MIN;
            for (auto i = fact.begin(); i != fact.end(); i++)
            {
                lol no = ((*i).first);
                lol c = p;

                while (c % q1 == 0)
                {
                    c /= no;
                }

                ans = max(c, ans);
            }
            cout << ans << endl;
        }
    }

    return 0;
}