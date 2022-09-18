#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol n, m, i, j, a, b;
    cin >> n >> m >> i >> j >> a >> b;
    bool f1 = false, f2 = false, f3 = false, f4 = false;
    lol a1 = LONG_LONG_MAX, a2 = LONG_LONG_MAX, a3 = LONG_LONG_MAX, a4 = LONG_LONG_MAX;
    if (n <=a || m <= b)
    {
        if (i == 1 && (j == m || j == 1))
            cout << 0;
        else if (i == n && (j == 1 || j == m))
            cout << 0;
        else
            cout << "Poor Inna and pony!";
    }
    else
    { // (1,m)
        if (abs(1 - i) % a == 0)
        {
            if (abs(m - j) % b == 0)
            {
                if (abs(abs(1 - i) / a - abs(m - j) / b) % 2 == 0)
                {
                    lol x = (abs(1 - i)) / a, y = (abs(m - j)) / b;
                    a1 = max(x, y);
                }
                else
                {
                    f1 = true;
                }
            }
            else
                f1 = true;
        }
        else
        {
            f1 = true;
        }
        //(1,1)
        if (abs(1 - i) % a == 0)
        {
            if (abs(1 - j) % b == 0)
            {
                if (abs(abs(1 - i) / a - abs(1 - j) / b) % 2 == 0)
                {
                    lol x = (abs(1 - i)) / a, y = (abs(1 - j)) / b;
                    a2 = max(x, y);
                }
                else
                    f2 = true;
            }
            else
                f2 = true;
        }
        else
        {
            f2 = true;
        }
        //(n,1)
        if (abs(n - i) % a == 0)
        {
            if (abs(1 - j) % b == 0)
            {
                if (abs(abs(n - i) / a - abs(1 - j) / b) % 2 == 0)
                {
                    lol x = (abs(n - i)) / a, y = (abs(1 - j)) / b;
                    a3 = max(x, y);
                }
                else
                    f3 = true;
            }
            else
                f3 = true;
        }
        else
        {
            f3 = true;
        }
        //(n,m)
        if (abs(n - i) % a == 0)
        {
            if (abs(m - j) % b == 0)
            {
                if (abs(abs(n - i) / a - abs(m - j) / b) % 2 == 0)
                {
                    lol x = (abs(n - i)) / a, y = (abs(m - j)) / b;
                    a4 = max(x, y);
                }
                else
                    f4 = true;
            }
            else
                f4 = true;
        }
        else
        {
            f4 = true;
        }
        if (f1 && f2 && f3 && f4)
        {
            cout << "Poor Inna and pony!";
        }
        else
            cout << min(min(a1, a2), min(a3, a4));
    }

    return 0;
}