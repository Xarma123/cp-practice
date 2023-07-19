#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    vector<lol> pw;
    lol c = 1;
    while (c <= (long long)2e9)
    {
        pw.push_back(c);
        c = c * 5ll;
    }

    lol t;
    cin >> t;
    while (t--)
    {
        lol n, m;
        cin >> n >> m;
        lol N = n;
        lol tw = 0;
        while (N % 2 == 0)
        {
            tw++;
            N /= 2;
        }
        lol fv = 0;
        while (N % 5 == 0)
        {
            fv++;
            N /= 5;
        }
        lol ans = 1;
        if (fv < tw)
        {
            lol e = tw - fv + 1;
            lol s = 0;
            while (s != e - 1)
            {
                lol md = (s + e) / 2;
                if (md == tw - fv + 1)
                    e = md;
                else if ((ans * 1ll * pw[md]) <= m)
                    s = md;
                else
                    e = md;
            }
            ans = ans * 1ll * pw[s];
        }
        else
        {
            lol e = fv - tw + 1;
            lol s = 0;
            while (s != e - 1)
            {
                lol md = (s + e) / 2;
                if (md == fv - tw + 1)
                    e = md;
                else if ((ans * (1ll << md)) <= m)
                    s = md;
                else
                    e = md;
            }
            ans = ans * (1ll << s);
        }
        while (ans * 10ll <= m)
        {
            ans = ans * 10ll;
        }

        lol s = 1, e = 2e9;
        while (s != e - 1)
        {
            lol md = (s + e) / 2;
            if (md * 1ll * ans <= m)
                s = md;
            else
                e = md;
        }
        cout << ans * 1ll * s * 1ll * n << '\n';
    }
}