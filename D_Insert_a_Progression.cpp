#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol t;
    cin >> t;
    while (t--)
    {
        lol n, x;
        cin >> n >> x;
        lol a[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        lol tex = LONG_LONG_MAX;
        lol mn = abs(a[0] - 1);
        for (lol i = 0; i < n; i++)
        {
            if (i + 1 < n)
            {
                lol l = a[i];
                lol r = a[i + 1];
                if (l > r)
                    swap(l, r);
                if (x <= l)
                {
                    tex = min(tex, 2ll * (l - x) + mn);
                }
                else if (x >= r)
                {
                    tex = min(tex, 2ll * (x - r) + mn);
                }
                else
                {
                    tex = min(tex, mn);
                }

                if (1 <= l)
                {
                    mn = min(mn, 2ll * (l - 1));
                }
                else if (1 >= r)
                {
                    mn = min(mn, 2ll * (1 - r));
                }
                else
                {
                    mn = min(mn, 0ll);
                }
            }
            else
            {
                tex = min(tex, mn + abs(a[i] - x));
            }
        }
        mn = abs(a[n - 1] - 1);
        for (lol i = n - 1; i >= 0; i--)
        {
            if (i - 1 >= 0)
            {
                lol l = a[i];
                lol r = a[i - 1];
                if (l > r)
                    swap(l, r);
                if (x <= l)
                {
                    tex = min(tex, 2ll * (l - x) + mn);
                }
                else if (x >= r)
                {
                    tex = min(tex, 2ll * (x - r) + mn);
                }
                else
                {
                    tex = min(tex, mn);
                }

                if (1 <= l)
                {
                    mn = min(mn, 2ll * (l - 1));
                }
                else if (1 >= r)
                {
                    mn = min(mn, 2ll * (1 - r));
                }
                else
                {
                    mn = min(mn, 0ll);
                }
            }
            else
            {
                tex = min(tex, mn + abs(a[i] - x));
            }
        }
        for (lol i = 0; i < n; i++)
        {
            if (i + 1 < n)
            {

                lol ne = abs(a[i] - 1) + abs(1 - x) + abs(x - a[i + 1]) - abs(a[i] - a[i + 1]);
                tex = min(tex, ne);
            }
        }
        lol c = abs(1 - x) + abs(1 - a[0]);
        tex = min(tex, c);
        c = abs(1 - x) + abs(a[0] - x);
        tex = min(tex, c);
        c = abs(1 - x) + abs(a[n - 1] - x);
        tex = min(tex, c);
        c = abs(1 - x) + abs(a[n - 1] - 1);
        tex = min(tex, c);

        for (lol i = 0; i < n - 1; i++)
        {
            tex += abs(a[i] - a[i + 1]);
        }
        cout << tex << '\n';
    }
}