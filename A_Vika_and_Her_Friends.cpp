#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        lol n, m, k;
        cin >> n >> m >> k;
        lol x, y;
        cin >> x >> y;
        bool ans = true;
        for (lol i = 0; i < k; i++)
        {
            lol a, b;
            cin >> a >> b;
            if ((abs(a - x) + abs(b - y)) % 2 == 0)
                ans = false;
        }
        if (ans)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}