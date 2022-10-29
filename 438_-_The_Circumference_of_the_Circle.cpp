#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long double a[6];
    while (cin >> a[0])
    {
        cin >> a[1];
        cin >> a[2];
        cin >> a[3];
        cin >> a[4];
        cin >> a[5];

        long double x1, x2, y1, y2;
        x1 = a[0];
        y1 = a[1];
        x2 = a[2];
        y2 = a[3];
        if (abs(y2 - y1) <= 1e-9)
        {
            x1 = a[2];
            y1 = a[3];
            x2 = a[4];
            y2 = a[5];
            long double m2 = (x1 - x2) / (y2 - y1);
            long double c2 = ((y1 + y2) - ((x1 - x2) / (y2 - y1)) * (x1 + x2)) / (long double)2;

            long double x = (a[0] + a[2]) / (long double)2;
            long double y = x * m2 + c2;

            cout << fixed << setprecision(10) << sqrtl(powl(x - x1, 2) + powl(y - y1, 2)) * (long double)3.141592653589793 * (long double)2 << endl;
        }
        else
        {
            long double m1 = (x1 - x2) / (y2 - y1);
            long double c1 = ((y1 + y2) - ((x1 - x2) / (y2 - y1)) * (x1 + x2)) / (long double)2;

            x1 = a[2];
            y1 = a[3];
            x2 = a[4];
            y2 = a[5];
            if (abs(y2 - y1) <= 1e-9)
            {

                long double x = (a[4] + a[2]) / (long double)2;
                long double y = x * m1 + c1;

                cout << fixed << setprecision(10) << sqrtl(powl(x - x1, 2) + powl(y - y1, 2)) * (long double)3.141592653589793 * (long double)2 << endl;
            }
            else
            {
                long double m2 = (x1 - x2) / (y2 - y1);
                long double c2 = ((y1 + y2) - ((x1 - x2) / (y2 - y1)) * (x1 + x2)) / (long double)2;

                long double x = (c1 - c2) / (m2 - m1);
                long double y = ((c1 - c2) / (m2 - m1)) * m1 + c1;

                cout << fixed << setprecision(10) << sqrtl(powl(x - x1, 2) + powl(y - y1, 2)) * (long double)3.141592653589793 * (long double)2 << endl;
            }
        }
    }

    return 0;
}