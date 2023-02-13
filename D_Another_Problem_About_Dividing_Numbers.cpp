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
        lol a, b, k;
        cin >> a >> b >> k;
        lol g = __gcd(a, b);
        lol c1 = a / g;
        lol c2 = b / g;
        lol mn;
        if (c1 == 1 && c2 == 1)
            mn = 0;
        if (c1 == 1 || c2 == 1)
            mn = 1;
        else
            mn = 2;
        lol mx = 0;
        for (lol i = 2; i * 1ll * i <= c1; i++)
        {
            while (c1 % i == 0)
            {
                mx++;
                c1 /= i;
            }
        }
        if (c1 > 1)
            mx++;
        for (lol i = 2; i * 1ll * i <= c2; i++)
        {
            while (c2 % i == 0)
            {
                mx++;
                c2 /= i;
            }
        }
        if (c2 > 1)
            mx++;
        lol qq = 0;
        for (lol i = 2; i * 1ll * i <= g; i++)
        {
            while (g % i == 0)
            {
                qq++;
                g /= i;
            }
        }
        if (g > 2)
            qq++;
        if (k < mn)
            cout << "NO";
        else if (k <= mx)
        {
            cout << "YES";
        }
        else
        {
            lol l = ceill((k - mx) / (long double)2);
            lol r = (k - mn) / 2;

            if (l <= r && qq >= l)
            {
                cout << "YES";
            }
            else
                cout << "NO";
        }
        cout << '\n';
    }

    return 0;
}