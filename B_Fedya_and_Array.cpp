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
        cout << x - y + 1 - 1 - y + x - 1 + 1 << '\n';
        for (lol i = y; i <= x; i++)
        {
            cout << i << " ";
        }
        for (lol i = x - 1; i >= y + 1; i--)
        {
            cout << i << " ";
        }
        cout << '\n';
    }

    return 0;
}