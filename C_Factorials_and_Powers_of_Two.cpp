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
        if (n & (n - 1) == 0)
            cout << 1 << endl;
        else
        {
            vector<lol> f;
            long long fact = 1;
            long long x = 2;
            lol ans = LONG_LONG_MAX;
            while (fact <= n)
            {
                f.push_back(fact);
                fact = fact * x;

                x++;
            }
            for (lol i = 0; i < powl(2, f.size()); i++)
            {
                lol s = 0;
                lol c = 0;
                for (lol j = 0; j < f.size(); j++)
                {
                    if ((i & (1 << j)))
                    {
                        c++;
                        s += f[j];
                    }
                }
                lol ex = n - s;
                if (ex < 0)
                {
                    continue;
                }
                else
                {
                    while (ex)
                    {
                        ex &= (ex - 1);
                        c++;
                    }
                    ans = min(ans, c);
                }
            }
            if (ans == LONG_LONG_MAX)
                cout << -1 << endl;
            else
                cout << ans << endl;
        }
    }

    return 0;
}