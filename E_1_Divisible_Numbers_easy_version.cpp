#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol t;
    cin >> t;
    while (t--)
    {
        lol a, b, c, d;
        cin >> a >> b >> c >> d;
        lol q = a * 1ll * b;
        bool ans = false;

        for (lol i = a + 1; i <= c && !ans; i++)
        {
            if (!ans)
            {
                lol hcf = __gcd(i, q);

                lol ex = q / hcf;

                if (((d / ex) * 1ll * ex) > b)
                {
                    cout << i << " " << ((d / ex) * 1ll * ex) << endl;
                    ans = true;
                }
            }
            if (i % q == 0 && !ans)
            {
                cout << i << " " << d << endl;
                ans = true;
            }
        }

        for (lol i = b + 1; i <= d && !ans; i++)
        {
            if (!ans)
            {
                lol hcf = __gcd(i, q);
                lol ex = q / hcf;
                if (((c / ex) * 1ll * ex) > a)
                {
                    cout << ((c / ex) * 1ll * ex) << " " << i << endl;
                    ans = true;
                }
            }
            if (i % q == 0 && !ans)
            {
                cout << c << " " << i << endl;
                ans = true;
            }
        }
        if (!ans)
            cout << -1 << " " << -1 << endl;
    }

    return 0;
}