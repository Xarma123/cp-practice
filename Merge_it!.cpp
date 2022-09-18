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
        lol a[3] = {0, 0, 0};
        while (n--)
        {
            lol t;
            cin >> t;
            a[t % 3]++;
        }

        lol ans = a[0];

        lol x = min(a[2], a[1]);

        ans += x;
        a[1] -= x, a[2] -= x;
        ans += (a[1] + a[2]) / 3;
        cout << ans << endl;
    }
    return 0;
}