#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        lol k, x;
        cin >> k >> x;
        lol m = 0;
        if (x >= (k) * (k + 1) / 2 + (k - 1) * (k) / 2)
        {
            m = 2 * k - 1;
        }
        else
        {
            if (x >= k * (k + 1) / 2)
            {
                x -= k * (k + 1) / 2;
                m += k;
                if (x > 0)
                {
                    lol n = ceil(((2 * k - 1) - (long double)sqrt(pow(2 * k - 1, 2) - (long double)8 * x)) / (long double)2);
                    m += n;
                }
            }
            else
            {
                lol n = ceil((-1 + (long double)sqrt(1 + (long double)8 * x)) / (long double)2);
                m += n;
            }
        }

        cout << m << endl;
    }

    return 0;
}