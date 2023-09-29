#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, x, y;
    cin >> n >> x >> y;
    lol a = 0, b = 0, c = 0, d = 0;
    for (lol i = 0; i < n; i++)
    {
        lol q, w;
        cin >> q >> w;
        if (q > x)
            a++;
        if (q < x)
            b++;
        if (w > y)
            c++;
        if (w < y)
            d++;
    }
    if (a >= max(b, max(c, d)))
    {
        cout << a << '\n';
        cout << x + 1 << " " << y << '\n';
    }
    else if (b >= max(a, max(c, d)))
    {
        cout << b << '\n';
        cout << x - 1 << " " << y << '\n';
    }
    else if (c >= max(a, max(b, d)))
    {
        cout << c << '\n';
        cout << x << " " << y + 1 << '\n';
    }
    else
    {
        cout << d << '\n';
        cout << x << " " << y - 1 << '\n';
    }
}