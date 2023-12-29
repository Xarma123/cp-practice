#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol t;
    cin >> t;
    while (t--)
    {
        lol x, y, k;
        cin >> x >> y >> k;
        if (y < x)
        {
            cout << x << '\n';
        }
        else
        {
            x = min(y, x + k);
            cout << y + (y - x) << '\n';
        }
    }

    return 0;
}
