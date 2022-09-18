#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{

    lol t;
    cin >> t;
    while (t--)
    {
        lol l, r;
        cin >> l >> r;

        lol ans = 0;
        lol x = 1;

        while (r != 0 || l != 0)
        {
            ans += r - l;
            r = r / 10;
            l = l / 10;
        }

        cout << ans << endl;
    }

    return 0;
}