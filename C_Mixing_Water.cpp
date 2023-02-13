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
        long double h, c, x;
        cin >> h >> c >> x;
        long double mid = (h + c) / (long double)2;
        if (x <= mid)
        {
            cout << 2 << '\n';
        }
        else
        {
            lol s = 1, e = 1e18;
            while (s != e - 1)
            {
                lol cups = (s + e) / 2;
                lol v = 2ll * cups - 1;
                long double temp = (((v / 2) + 1) * h + (v / 2) * c) / (long double)v;
                if (temp >= x)
                    s = cups;
                else
                    e = cups;
            }
            lol v = 2ll * s - 1;
            long double temp = (((v / 2) + 1) * h + (v / 2) * c) / (long double)v;
            long double dif = abs(temp - x);
            v = 2ll * e - 1;
            temp = (((v / 2) + 1) * h + (v / 2) * c) / (long double)v;
            if (dif > abs(temp - x))
                s = e;
            cout << 2ll * s - 1 << '\n';
        }
    }

    return 0;
}