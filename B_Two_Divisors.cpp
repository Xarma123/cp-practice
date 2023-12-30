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
        lol a, b;
        cin >> a >> b;
        lol v = b * 1ll * (a / (long long)__gcd(a, b));
        if (v == b)
        {
            if (v % 2 == 0)
                v = v * 2ll;
            else
            {
                lol c = -1;
                for (lol i = 3; i * 1ll * i <= v; i += 2)
                {
                    if (v % i == 0)
                    {
                        c = i;
                        break;
                    }
                }
                if (c == -1)
                    c = v;
                v = v * 1ll * c;
            }
        }
        cout << v << '\n';
    }

    return 0;
}
