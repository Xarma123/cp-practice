#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, x;
    cin >> n >> x;
    lol d[2ll * n];
    for (lol i = 0; i < n; i++)
    {
        cin >> d[i];
    }
    for (lol i = n; i < 2ll * n; i++)
    {
        d[i] = d[i - n];
    }
    lol h[2ll * n];
    for (lol i = 0; i < 2ll * n; i++)
    {
        h[i] = d[i] * 1ll * (d[i] + 1) / 2ll;
        if (i > 0)
            h[i] += h[i - 1];
    }
    lol c[2ll * n];
    for (lol i = 0; i < 2ll * n; i++)
    {
        c[i] = d[i];
        if (i > 0)
            c[i] += c[i - 1];
    }
    lol q = LONG_LONG_MIN;
    for (lol i = 0; i < 2ll * n; i++)
    {

        lol s = -1, e = i + 1;
        while (s != e - 1)
        {
            lol m = (s + e) / 2;
            if (m == -1)
            {
                s = m;
            }
            else if (m == i + 1)
                e = m;
            {
                lol v = c[i];
                if (m - 1 >= 0)
                    v -= c[m - 1];
                if (v <= x)
                {
                    e = m;
                }
                else
                    s = m;
            }
        }

        lol r = x;
        lol ans = 0;
        if (e <= i)
        {
            lol v = c[i];
            ans += h[i];
            if (e - 1 >= 0)
            {
                v -= c[e - 1];
                ans -= h[e - 1];
            }
            r -= v;
        }
        
        if (e - 1 >= 0 && r > 0)
        {

            ans += r * 1ll * (d[e - 1] + d[e - 1] - r + 1) / 2ll;
        }
        q = max(q, ans);
    }
    cout << q;
}