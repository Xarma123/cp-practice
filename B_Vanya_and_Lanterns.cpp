#include <bits/stdc++.h>
#define lol long double
using namespace std;
int main()
{
    lol n, l;
    cin >> n >> l;
    lol a[n];
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vector<lol> a;
    while (x.size())
    {
        a.push_back((*x.begin()));
        x.erase(a.back());
    }
    long double s = -1;
    long double e = 2 * 1ll * l;
    while (e - s > 1e9)
    {
        long double m = (s + e) / (long double)2;
        if (m == -1)
            s = m;
        else
        {
            long double v = m;
            lol i;
            for (i = 0; i < a.size(); i++)
            {
                if (a[i] - v > 1e-9)
                {
                    s = m;
                    break;
                }
                else
                {
                    v = a[i] + m + m;
                }
            }
            if (i != a.size())
                continue;
            if (a.back() + m < l)
                s = m;
            else
                e = m;
        }
    }
    cout << e;

    return 0;
}