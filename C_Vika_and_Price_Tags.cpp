#include <bits/stdc++.h>
using namespace std;
#define lol long long
lol solve(lol a, lol b)
{
    if (a == 0)
        return 0;
    if (b == 0)
        return 1;
    if (a >= b)
    {
        lol x = (a - b) / b;
        if (x % 2 == 0)
        {
            return (x / 2) * 3ll + 1 + solve(b, abs(a - (x + 1) * 1ll * b));
        }
        else
        {
            return (x / 2) * 3ll + 2 + solve(a - x * 1ll * b, abs(a - (x + 1) * 1ll * b));
        }
    }
    else
    {
        lol x = (b - a) / a;
        if (x == 0)
        {
            return 1 + solve(b, b - a);
        }
        else if (x % 2)
        {
            return (x / 2) * 3ll + 3 + solve(a, abs(b - (x + 1) * 1ll * a));
        }
        else
        {
            return (x / 2) * 3ll + 1 + solve(b - x * 1ll * a, abs(b - (x + 1) * 1ll * a));
        }
    }
}
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        lol n;
        cin >> n;
        lol a[n], b[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (lol i = 0; i < n; i++)
        {
            cin >> b[i];
        }
        bool ans = true;
        lol c = -1;
        for (lol i = 0; i < n; i++)
        {
            if (a[i] == 0 && b[i] == 0)
                continue;
            if (c == -1)
                c = solve(a[i], b[i]) % 3;
            else if (c != (solve(a[i], b[i]) % 3))
                ans = false;
        }
        if (ans)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}