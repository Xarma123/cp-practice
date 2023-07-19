#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        lol l, r, x;
        cin >> l >> r >> x;
        lol a, b;
        cin >> a >> b;
        if (a == b)
            cout << 0 << '\n';
        else if ((long long)abs(a - b) >= x)
        {
            cout << 1 << '\n';
        }
        else
        {
            if ((long long)abs(a - l) >= x && (long long)abs(l - b) >= x)
            {
                cout << 2 << '\n';
            }
            else if ((long long)abs(a - r) >= x && (long long)abs(r - b) >= x)
            {
                cout << 2 << '\n';
            }
            else if ((long long)abs(b - l) < x && (long long)abs(r - b) < x)
            {
                cout << -1 << '\n';
            }
            else if ((long long)abs(a - l) < x && (long long)abs(r - a) < x)
            {
                cout << -1 << '\n';
            }
            else
                cout << 3 << '\n';
        }
    }
}