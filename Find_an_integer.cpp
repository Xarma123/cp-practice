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
        lol x, y;
        cin >> x >> y;
        if (x < y)
            swap(x, y);
        if (y == x)
        {
            cout << x << '\n';
        }
        else if (y == 1)
        {
            cout << x - 1 << '\n';
        }
        else
            cout << x * 1ll * y - x - y << '\n';
    }

    return 0;
}