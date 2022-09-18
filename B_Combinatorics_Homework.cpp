#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        lol a, b, c, m;
        cin >> a >> b >> c >> m;
        lol d = 0;
        if (a > 0)
            d += a - 1;
        if (b > 0)
            d += b - 1;
        if (c > 0)
            d += c - 1;
        if (d == m)
            cout << "YES" << endl;
        else if (d < m)
            cout << "NO" << endl;
        else
        {
            if (a < b)
                swap(a, b);
            if (a < c)
                swap(a, c);
            if (b < c)
                swap(b, c);

            a = a - 1 - (c + b);
           
            if (m >= a)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
    }

    return 0;
}