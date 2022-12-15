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
        lol n;
        cin >> n;
        lol a[n];
        lol v = 0;
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
            v |= a[i];
        }
        lol cr[n];
        lol cl[n];
        for (lol i = 0; i < n; i++)
        {
            cl[i] = a[i];
            if (i)
                cl[i] |= cl[i - 1];
        }

        for (lol i = n - 1; i >= 0; i--)
        {
            if (i == n - 1)
                cr[i] = a[i];
            else
                cr[i] = a[i] | cr[i + 1];
        }

        lol l[30];
        memset(l, -1, sizeof(l));
        lol cor = 0;
        lol ans = -1;
        lol q[n];
        memset(q, -1, sizeof(q));
        for (lol i = 0; i < n; i++)
        {
            cor |= a[i];
            bool f = true;
            for (lol b = 0; b < 30; b++)
            {
                if ((v & (1ll << b)))
                {
                    if (!(cor & (1ll << b)))
                    {
                        f = false;
                    }
                }
            }
            for (lol b = 0; b < 30; b++)
            {
                if ((a[i] & (1ll << b)))
                {
                    l[b] = i;
                }
            }

            if (f)
            {

                lol x = cor ^ v;
                lol mx = -1;
                lol mn = i;
                for (lol b = 0; b < 30; b++)
                {
                    if ((x & (1ll << b)))
                    {
                        mx = max(mx, l[b]);
                    }

                    if ((v & (1ll << b)))
                    {
                        mn = min(mn, l[b]);
                    }
                }
                if (mn > mx)
                {
                    q[i] = mx + 1;
                }
            }
        }

        if (v == 0)
        {
            cout << n << endl;
        }
        else
        {
            lol s=0,e=n;
        }
    }

    return 0;
}