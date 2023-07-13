#include <bits/stdc++.h>
using namespace std;
#define lol unsigned long long
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        long n, d, h;
        cin >> n >> d >> h;
        long y[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> y[i];
        }
        long double ans = 0;
        for (lol i = 0; i < n; i++)
        {
            if (i + 1 < n && y[i + 1] <= y[i] + h)
            {
                lol h_ = y[i] + h - y[i + 1];
                ans += (h * 1ll * h - h_ * 1ll * h_) / (long double)(2ll * h);
            }
            else
                ans += h / (long double)2;
        }
        ans = ans * (long double)d;

        cout << fixed << setprecision(10);
        cout << ans  << '\n';
    }
}