#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n;
    cin >> n;
    lol m;
    cin >> m;
    lol a[n], b[n];
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (lol i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    long double s = 0, e = 1e10;
    while (abs(e - s) > 1e-9)
    {
        long double md = (s + e) / (long double)2;
        long double f = md;
        for (lol i = 0; i < n; i++)
        {
            if (i)
            {
                f -= (f + m) / (long double)b[i];
            }
            f -= (f + m) / (long double)a[i];
        }
        f -= (f + m) / (long double)b[0];
        if (f >= (long double)0)
        {
            e = md;
        }
        else
            s = md;
    }
    if (abs(e - (1e10)) <= 1e-10)
    {
        cout << -1;
    }
    else
        cout << fixed << setprecision(10) << e;
}