#include <bits/stdc++.h>
#define lol long long
using namespace std;
lol mod = 1e9 + 7;
lol pw(lol a, lol b)
{
    lol res = 1;
    while (b)
    {
        if (b % 2)
            res = (res * 1ll * a) % mod;
        b /= 2;
        a = (a * 1ll * a) % mod;
    }
    return res;
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol t;
    cin >> t;
    while (t--)
    {
        lol n, m;
        cin >> n >> m;
        lol p[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> p[i];
            p[i]--;
        }
        lol a[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        lol c = 0;
        lol z = -1;
        lol q = -1;
        for (lol i = 0; i < n; i++)
        {
            if (a[i] == 0)
            {
                if (p[i] != i)
                    c++;
            }

            if (a[p[i]] != 0 && a[p[i]] != -1)
            {
                if (q == -1)
                {
                    q = a[p[i]];
                }
                else if (q != a[p[i]])
                {
                    q = LONG_LONG_MAX;
                    break;
                }
            }

            a[i] = z;
            a[p[i]] = z;
        }
        if (q == LONG_LONG_MAX)
            cout << 0 << '\n';
        else
        {
            if (q == -1)
                c++;
            cout << pw(m, c) << '\n';
        }
    }

    return 0;
}