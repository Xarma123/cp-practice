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
        lol n;
        cin >> n;
        lol a, b, c;
        a = b = c = LONG_LONG_MAX;
        while (n--)
        {
            lol m;
            cin >> m;
            string s;
            cin >> s;
            if (s == "11")
                c = min(c, m);
            else if (s == "01")
                b = min(b, m);
            else if (s == "10")
                a = min(a, m);
        }
        if (c != LONG_LONG_MAX && a != LONG_LONG_MAX && b != LONG_LONG_MAX)
        {
            cout << min(c, a + b) << '\n';
        }
        else if (c != LONG_LONG_MAX)
            cout << c << '\n';
        else if (a != LONG_LONG_MAX && b != LONG_LONG_MAX)
            cout << a + b << '\n';
        else
            cout << -1 << '\n';
    }

    return 0;
}