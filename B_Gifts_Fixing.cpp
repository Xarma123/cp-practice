#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        lol n;
        cin >> n;
        lol a[n];
        lol c = INT_MAX;
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
            c = min(c, a[i]);
        }
        lol b[n];
        lol o = INT_MAX;
        for (lol i = 0; i < n; i++)
        {
            cin >> b[i];
            o = min(o, b[i]);
        }
        lol ans = 0;
        for (lol i = 0; i < n; i++)
        {
            lol x = a[i] - c;
            lol y = b[i] - o;
            ans += min(x, y) + abs(x - y);
        }
        cout << ans << endl;
    }

    return 0;
}